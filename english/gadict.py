# -*- coding: utf-8 -*-
"""Anki card writer"""

import os
import io
import sys
import tempfile
import shutil
import signal
import regex

import hashlib

import anki
from anki.exporting import AnkiPackageExporter

import gadict
import gadict_freq


FINAME = None
FONAME = None
FDELNAME = None
NAME = None
LANGS = None
FREQ_SOURCES = []
RICH_MODE = False

ARG_NAME_RE = regex.compile("-name=(.+)")
# -lang:ru,uk
ARG_LANG_RE = regex.compile("-lang:(.+)")
# -freq:var:TAG=FILE or -freq:freq:TAG=FILE
ARG_FREQ_RE = regex.compile("-freq:(freq|var):([^=]+)=(.+)")
ARG_DELFILE_RE = regex.compile("-delfile=(.+)")

look_for_files = False
for idx in range(1, len(sys.argv)):
    arg = sys.argv[idx]
    if arg == "--":
        look_for_files = True
        continue
    if not look_for_files:
        m = ARG_NAME_RE.match(arg)
        if m:
            NAME = m.group(1)
            continue
        m = ARG_LANG_RE.match(arg)
        if m:
            LANGS = set(m.group(1).split(","))
            for lang in LANGS:
                if len(lang) != 2:
                    raise Exception("Incorrect language specification: '{:s}'".format(arg))
            continue
        m = ARG_FREQ_RE.match(arg)
        if m:
            mode = m.group(1)
            tag = m.group(2)
            fname = m.group(3)
            with io.open(fname, mode='r', buffering=1, encoding="utf-8") as stream:
                if mode == "var":
                    parser = gadict_freq.WordformParser(stream)
                elif mode == "freq":
                    parser = gadict_freq.FreqlistParser(stream)
                else:
                    raise Exception("Unsupported mode: '{:s}'".format(mode))
                wlist = parser.parse()
            FREQ_SOURCES.append((tag, set(wlist)))
            continue
        m = ARG_DELFILE_RE.match(arg)
        if m:
            FDELNAME = m.group(1)
            continue
        if arg == "-rich":
            RICH_MODE = True
            continue
        if arg.startswith("-"):
            raise Exception("Unsupported option format: '{:s}'".format(arg))
    if not FINAME:
        FINAME = arg
        continue
    if not FONAME:
        FONAME = arg
        continue
    raise Exception("Unnecessary argument: '{:s}'".format(arg))

if not FINAME:
    raise Exception("Input file name is not passed...")
FIN = io.open(FINAME, mode='r', buffering=1, encoding="utf-8")

PARSER = gadict.Parser()
try:
    DOM = PARSER.parse(FIN)
except gadict.ParseException as ex:
    sys.stdout.write("{:s}{:s}\n".format(FINAME, repr(ex)))
    if __debug__:
        import traceback
        traceback.print_exc()
    exit(1)
finally:
    FIN.close()


def cleanup(collection, tmpdir):
    if collection:
        collection.close()
    if tmpdir:
        shutil.rmtree(tmpdir, ignore_errors=True)

# signal.signal(signal.SIGINT, lambda signal, frame: cleanup())


if FONAME is None:
    raise Exception("Output file name is not passed...")
# Looks like anki libs change working directory to media directory of current deck
# Therefore absolute path should be stored before creating temporary deck
FONAME = os.path.abspath(FONAME)
TMPDIR = tempfile.mkdtemp(dir=os.path.dirname(FONAME))

if not NAME:
    NAME, _ = os.path.splitext(os.path.basename(FINAME))

if FDELNAME:
    FDEL = io.open(FDELNAME, mode='r', buffering=1, encoding="utf-8")
else:
    FDEL = None

################################################################

MODEL_CSS = """
.card {
  font-family: arial;
  font-size: 20px;
  text-align: center;
  color: black;
  background-color: white;
}
.ask {
  margin-bottom: 1.2em;
}
span.headword {
  font-weight: bolt;
}
.pron {
  color: magenta;
}
.pos {
  color: green;
  font-style: italic;
}
.lang {
  color: red;
  font-style: italic;
}
.topic {
  color: #B04080;
}
.ant {
  color: #404080;
}
.syn {
  color: #804040;
}
.rel {
  color: #604080;
}
.hyper {
  color: #600080;
}
.hypo {
  color: #606080;
}
.attrs {
  color: blue;
}
span.ex {
  font-style: italic;
  font-size: .85em;
}
div.glos .lang {
  color: brown;
}
span.glos {
  font-size: .95em;
}
.freq {
  color: red;
  font-weight: bold;
  font-size: small;
}
.del {
  color: red;
  font-weight: bold;
}
"""


def note_add_tags(note, tags):
    if isinstance(tags, str):
        note.tags = [tags]
    elif isinstance(tags, list):
        note.tags = tags
    elif tags is None:
        pass
    else:
        raise Exception('Expecting string or list of tags...')


class AnkiDbBuilder:

    def __init__(self, tmpdir, name):
        self.tmpdir = tmpdir
        self.name = name

        self.collection = collection = anki.Collection(os.path.join(self.tmpdir, 'collection.anki2'))

        deck_id = collection.decks.id(self.name)

        # It is essential to keep model['id'] unchanged between upgrades!!
        model_id = int(hashlib.sha1(self.name).hexdigest(), 16) % (2**63)

        ################################################################
        # Regular card model. SafeBack doesn't include examples to not spoil
        # word spelling.
        model = collection.models.new(self.name + "_frontback")
        model['did'] = deck_id
        model['css'] = MODEL_CSS

        collection.models.addField(model, collection.models.newField('Front'))
        collection.models.addField(model, collection.models.newField('Back'))
        collection.models.addField(model, collection.models.newField('SafeBack'))
        collection.models.addField(model, collection.models.newField('Freq'))

        tmpl = collection.models.newTemplate('Front -> Back')
        tmpl['qfmt'] = '<div class="front">{{Front}}</div><div class="freq">{{Freq}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Back}}</div>'
        collection.models.addTemplate(model, tmpl)

        tmpl = collection.models.newTemplate('SafeBack -> Front')
        tmpl['qfmt'] = '<div class="safe-back">{{SafeBack}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="front">{{Front}}</div><div class="freq">{{Freq}}</div>'
        collection.models.addTemplate(model, tmpl)

        # Equivalent of ``collection.models.add(model)`` without setting
        # auto-generated ID.
        # Increment +1 is for keeping model['id'] unique from previous v0.9 release.
        model['id'] = model_id + 1
        collection.models.update(model)
        collection.models.save(model)
        self.model = model
        # collection.models.setCurrent(model)

        if not RICH_MODE:
            return

        ################################################################
        # Model for irregular verbs.
        model = collection.models.new(self.name + "_irrverb")
        model['did'] = deck_id
        model['css'] = MODEL_CSS

        collection.models.addField(model, collection.models.newField('V1'))
        collection.models.addField(model, collection.models.newField('V2'))
        collection.models.addField(model, collection.models.newField('V3'))
        collection.models.addField(model, collection.models.newField('V2alt'))
        collection.models.addField(model, collection.models.newField('V3alt'))
        collection.models.addField(model, collection.models.newField('Front'))
        collection.models.addField(model, collection.models.newField('Back'))
        collection.models.addField(model, collection.models.newField('Freq'))

        question = u"<div class='ask'>Find irregular verb:</div>"

        tmpl = collection.models.newTemplate('V1 -> Back')
        tmpl['qfmt'] = question + '<div class="front">{{V1}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Front}}</div><div class="freq">{{Freq}}</div><div class="back">{{Back}}</div>'
        collection.models.addTemplate(model, tmpl)

        tmpl = collection.models.newTemplate('V2 -> Back')
        tmpl['qfmt'] = question + '<div class="front">{{V2}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Front}}</div><div class="freq">{{Freq}}</div><div class="back">{{Back}}</div>'
        collection.models.addTemplate(model, tmpl)

        tmpl = collection.models.newTemplate('V3 -> Back')
        tmpl['qfmt'] = question + '<div class="front">{{V3}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Front}}</div><div class="freq">{{Freq}}</div><div class="back">{{Back}}</div>'
        collection.models.addTemplate(model, tmpl)

        tmpl = collection.models.newTemplate('V2alt -> Back')
        tmpl['qfmt'] = question + '<div class="front">{{V2alt}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Front}}</div><div class="freq">{{Freq}}</div><div class="back">{{Back}}</div>'
        collection.models.addTemplate(model, tmpl)

        tmpl = collection.models.newTemplate('V3alt -> Back')
        tmpl['qfmt'] = question + '<div class="front">{{V3alt}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Front}}</div><div class="freq">{{Freq}}</div><div class="back">{{Back}}</div>'
        collection.models.addTemplate(model, tmpl)

        model['id'] = model_id + 2          # Keep model['id'] unique.
        collection.models.update(model)
        collection.models.save(model)
        self.model_irr = model

        ################################################################
        # Model for irregular plurals.
        model = collection.models.new(self.name + "_plural")
        model['did'] = deck_id
        model['css'] = MODEL_CSS

        collection.models.addField(model, collection.models.newField('Singular'))
        collection.models.addField(model, collection.models.newField('Plural'))
        collection.models.addField(model, collection.models.newField('Front'))
        collection.models.addField(model, collection.models.newField('Back'))
        collection.models.addField(model, collection.models.newField('Freq'))

        question = u"<div class='ask'>Find singular/plural form:</div>"

        tmpl = collection.models.newTemplate('Singular -> Back')
        tmpl['qfmt'] = question + '<div class="front">{{Singular}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Front}}</div><div class="freq">{{Freq}}</div><div class="back">{{Back}}</div>'
        collection.models.addTemplate(model, tmpl)

        tmpl = collection.models.newTemplate('Plural -> Back')
        tmpl['qfmt'] = question + '<div class="front">{{Plural}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Front}}</div><div class="freq">{{Freq}}</div><div class="back">{{Back}}</div>'
        collection.models.addTemplate(model, tmpl)

        model['id'] = model_id + 3          # Keep model['id'] unique.
        collection.models.update(model)
        collection.models.save(model)
        self.model_pl = model

    def guid(self, nodetype, headword, unambiguous):
        """
        :nodetype     used to generate different notes from same headword
        :unambiguous  used if several subsequent article with same headword (and different pronunciation)
        """
        if unambiguous > 0:
            h = hashlib.md5(":".join((self.name, nodetype, headword, str(unambiguous))))
        else:
            h = hashlib.md5(":".join((self.name, nodetype, headword)))
        return h.hexdigest()

    def add_note(self, headword, unambiguous, front, back, safeback, freq="", tags=None):
        note = anki.notes.Note(self.collection, self.model)
        note['Front'] = front
        note['Back'] = back
        note['SafeBack'] = safeback
        note['Freq'] = freq
        note_add_tags(note, tags)
        note.guid = self.guid("front/back", headword, unambiguous)
        self.collection.addNote(note)

    def add_note_irr(self, headword, unambiguous, v1, v2, v2alt, v3, v3alt, front, back, freq, tags=None):
        note = anki.notes.Note(self.collection, self.model_irr)
        note['V1'] = v1
        note['V2'] = v2
        note['V3'] = v3
        note['V2alt'] = v2alt
        note['V3alt'] = v3alt
        note['Front'] = front
        note['Back'] = back
        note['Freq'] = freq
        note_add_tags(note, tags)
        note.guid = self.guid("irregular verb", headword, unambiguous)
        self.collection.addNote(note)

    def add_note_pl(self, headword, unambiguous, singular, plural, front, back, freq, tags=None):
        note = anki.notes.Note(self.collection, self.model_pl)
        note['Singular'] = singular
        note['Plural'] = plural
        note['Front'] = front
        note['Back'] = back
        note['Freq'] = freq
        note_add_tags(note, tags)
        note.guid = self.guid("singular/plural noun", headword, unambiguous)
        self.collection.addNote(note)

    def export(self, fname):
        export = AnkiPackageExporter(self.collection)
        export.exportInto(fname)

    def close(self):
        self.collection.close()


def write_sense(buf, sense, with_examples=True):
    buf.append("<div class='sense'>")
    if sense.pos:
        buf.append("<span class='pos'>")
        buf.append(sense.pos)
        buf.append("</span>")
    have_ref = False
    if sense.topic_list and len(sense.topic_list) > 0:
        have_ref = True
        buf.append(u" <span class='topic'>⌊")
        buf.append(u", ".join(sense.topic_list))
        buf.append(u"⌉</span>")
    if sense.ant_list and len(sense.ant_list) > 0:
        have_ref = True
        buf.append(" <span class='ant'>ant: ")
        buf.append("; ".join(sense.ant_list))
        buf.append("</span>")
    if sense.syn_list and len(sense.syn_list) > 0:
        have_ref = True
        buf.append(" <span class='syn'>syn: ")
        buf.append("; ".join(sense.syn_list))
        buf.append("</span>")
    if sense.hyper_list and len(sense.hyper_list) > 0:
        have_ref = True
        buf.append(" <span class='hyper'>hyper: ")
        buf.append("; ".join(sense.hyper_list))
        buf.append("</span>")
    if sense.hypo_list and len(sense.hypo_list) > 0:
        have_ref = True
        buf.append(" <span class='hypo'>hypo: ")
        buf.append("; ".join(sense.hypo_list))
        buf.append("</span>")
    if sense.rel_list and len(sense.rel_list) > 0:
        have_ref = True
        buf.append(" <span class='rel'>rel: ")
        buf.append("; ".join(sense.rel_list))
        buf.append("</span>")
    for (lang, tr) in sense.tr_list or []:
        if len(sense.tr_list) > 1 or have_ref:
            buf.append("<div class='sense'>")
        buf.append(" <span class='lang'>")
        buf.append(lang)
        buf.append("</span>")
        buf.append(" <span class='tr'>")
        buf.append(tr)
        buf.append("</span>")
        if len(sense.tr_list) > 1 or have_ref:
            buf.append("</div>")
    for (lang, tr) in sense.glos_list or []:
        buf.append("<div class='glos'>")
        buf.append(" <span class='lang'>")
        buf.append(lang)
        buf.append("</span>")
        buf.append(" <span class='glos'>")
        buf.append(tr)
        buf.append("</span>")
        buf.append("</div>")
    for (lang, tr) in (with_examples and sense.ex_list) or []:
        buf.append("<div class='ex'>")
        buf.append(" <span class='lang'>")
        buf.append(lang)
        buf.append("</span>")
        buf.append(" <span class='ex'>")
        buf.append(tr)
        buf.append("</span>")
        buf.append("</div>")

try:
    BUILDER = AnkiDbBuilder(TMPDIR, NAME)

    for identity in FDEL or []:
        identity = identity.strip()
        warnmsg = "<div class='del'>Please delete this note ({})</div>".format(identity)
        BUILDER.add_note(identity, 0, warnmsg, warnmsg, warnmsg, tags="del")
        BUILDER.add_note_irr(identity, 0, warnmsg, warnmsg, warnmsg, warnmsg, warnmsg, warnmsg, warnmsg, freq="", tags="del")
        BUILDER.add_note_pl(identity, 0, warnmsg, warnmsg, warnmsg, warnmsg, freq="", tags="del")

    prev_identity = None
    unambiguous = 0
    for (headwords, translations) in DOM[1:]:
        identity = headwords[0].headword
        if 'rare' in headwords[0].attrs:
            continue
        freqtags = []
        for (freqtag, freqset) in FREQ_SOURCES:
            if identity in freqset:
                freqtags.append(freqtag)
        if prev_identity == identity:
            unambiguous += 1
        else:
            prev_identity = identity
            unambiguous = 0
        freqmsg = " "
        if len(freqtags) > 0:
            freqmsg = ",".join(freqtags)
        buf = []
        v1, v2, v3, v2alt, v3alt = (None, None, None, None, None)
        singular, plural = (None, None)
        for hw in headwords:
            buf.append("<div clsas='headword'>")
            buf.append("<span clsas='headword'>")
            buf.append(hw.headword)
            buf.append("</span>")
            if hw.pron is not None:
                buf.append(" <span class='pron'>[")
                buf.append(hw.pron)
                buf.append("]</span>")
            if len(hw.attrs) > 0:
                l = [u"«"+x+u"»" for x in hw.attrs]
                l.sort()
                buf.append("<span class='attrs'>")
                buf.append(", ".join(l))
                buf.append("</span>")
            if 'v1' in hw.attrs:
                v1 = (hw.headword, hw.pron)
            if 'v2' in hw.attrs:
                if v2:
                    v2alt = (hw.headword, hw.pron)
                else:
                    v2 = (hw.headword, hw.pron)
            if 'v3' in hw.attrs:
                if v3:
                    v3alt = (hw.headword, hw.pron)
                else:
                    v3 = (hw.headword, hw.pron)
            if 's' in hw.attrs:
                singular = (hw.headword, hw.pron)
            if 'pl' in hw.attrs:
                plural = (hw.headword, hw.pron)
            buf.append("</div>")
        direct_from = "".join(buf)
        buf = []
        for sense in translations:
            write_sense(buf, sense, with_examples=True)
        direct_to = "".join(buf)
        buf = []
        for sense in translations:
            write_sense(buf, sense, with_examples=False)
        reverse_from = "".join(buf)         # without examples!!
        BUILDER.add_note(identity, unambiguous, direct_from, direct_to, reverse_from, freqmsg)
        if v1 and v2 and v3 and RICH_MODE:
            riddle1 = u"<span class='headword'>{}</span> <span class='pron'>[{}]</span> <span class='attrs'>v1</span>".format(v1[0], v1[1])
            riddle2 = u"<span class='headword'>{}</span> <span class='pron'>[{}]</span> <span class='attrs'>v2</span>".format(v2[0], v2[1])
            riddle3 = u"<span class='headword'>{}</span> <span class='pron'>[{}]</span> <span class='attrs'>v3</span>".format(v3[0], v3[1])
            if v2alt:
                riddle2alt = u"<span class='headword'>{}</span> <span class='pron'>[{}]</span> <span class='attrs'>v2</span>".format(v2alt[0], v2alt[1])
            else:
                riddle2alt = u""
            if v3alt:
                riddle3alt = u"<span class='headword'>{}</span> <span class='pron'>[{}]</span> <span class='attrs'>v3</span>".format(v3alt[0], v3alt[1])
            else:
                riddle3alt = u""
            BUILDER.add_note_irr(identity, unambiguous, riddle1, riddle2, riddle2alt, riddle3, riddle3alt, direct_from, direct_to, freqmsg)
        if singular and plural and RICH_MODE:
            riddle_s = u"<span class='headword'>{}</span> <span class='pron'>[{}]</span> <span class='attrs'>s</span>".format(singular[0], singular[1])
            riddle_pl = u"<span class='headword'>{}</span> <span class='pron'>[{}]</span> <span class='attrs'>pl</span>".format(plural[0], plural[1])
            BUILDER.add_note_pl(identity, unambiguous, riddle_s, riddle_pl, direct_from, direct_to, freqmsg)

    BUILDER.export(FONAME)
finally:
    BUILDER.close()
    shutil.rmtree(TMPDIR, ignore_errors=True)
