# -*- coding: utf-8 -*-
import os
import io
import sys
import tempfile
import shutil
import signal
import re as regex

sys.path.append("/Users/philip/study/anki/")

import hashlib

import anki
from anki.exporting import AnkiPackageExporter

ARG_NAME_RE = regex.compile("-name=(.+)")
# -lang:ru,uk
ARG_LANG_RE = regex.compile("-lang:(.+)")
# -freq:var:TAG=FILE or -freq:freq:TAG=FILE
ARG_DELFILE_RE = regex.compile("-delfile=(.+)")
RICH_MODE = None
FINAME = None
FONAME = None
NAME = None

for idx in range(1, len(sys.argv)):
    arg = sys.argv[idx]
    if not FINAME:
        FINAME = arg
        continue
    if not FONAME:
        FONAME = arg
        continue

with io.open(FINAME, mode='r', buffering=1, encoding="utf-8") as FIN:
    DOM = FIN.readlines()

#if FONAME is None:
#    raise Exception("Output file name is not passed...")
# Looks like anki libs change working directory to media directory of current deck
# Therefore absolute path should be stored before creating temporary deck
#FONAME = os.path.abspath(FONAME)
#TMPDIR = tempfile.mkdtemp(dir=os.path.dirname(FONAME))

if not NAME:
    NAME, _ = os.path.splitext(os.path.basename(FINAME))

MODEL_CSS="""
.card {
 font-family: arial;
 font-size: 14px;
 text-align: left;
 color: black;
 background-color: white;
}
h1,h2,h3,h4,h5,h6 {
 font-weight:700
 -webkit-font-smoothing:antialiased;
 margin:20px 0 10px;
 padding:0;
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
        model_id = int(hashlib.sha1(self.name.encode('utf-8')).hexdigest(), 16) % (2**63)

        ################################################################
        # Regular card model. SafeBack doesn't include examples to not spoil
        # word spelling.
        model = collection.models.new(self.name + "_frontback")
        model['did'] = deck_id
        model['css'] = MODEL_CSS

        collection.models.addField(model, collection.models.newField('Front'))
        collection.models.addField(model, collection.models.newField('Back'))

        tmpl = collection.models.newTemplate('Front -> Back')
        tmpl['qfmt'] = '<div class="front">{{Front}}</div>'
        tmpl['afmt'] = '{{FrontSide}}<hr id=answer><div class="back">{{Back}}</div>'
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


    def guid(self, nodetype, headword, unambiguous):
        """
        :nodetype     used to generate different notes from same headword
        :unambiguous  used if several subsequent article with same headword (and different pronunciation)
        """
        if unambiguous > 0:
            h = hashlib.md5(":".join((self.name, nodetype, headword, str(unambiguous))).encode('utf-8'))
        else:
            h = hashlib.md5(":".join((self.name, nodetype, headword)).encode('utf-8'))
        return h.hexdigest()

    def add_note(self, headword, unambiguous, front, back, tags=None):
        note = anki.notes.Note(self.collection, self.model)
        note['Front'] = front
        note['Back'] = back
        note_add_tags(note, tags)
        note.guid = self.guid("front/back", headword, unambiguous)
        self.collection.addNote(note)

    def export(self, fname):
        export = AnkiPackageExporter(self.collection)
        export.exportInto("/Users/philip/abcd.apkg")

    def close(self):
        self.collection.close()

try:
    BUILDER = AnkiDbBuilder(TMPDIR, NAME)
    print("TMPDIR %s NAME %s" % (TMPDIR, NAME))

    prev_identity = None
    unambiguous = 0

    buf = []
    for hw in DOM[1:]:
        buf.append(hw)
    direct_from = DOM[0]
    identity = NAME
    direct_to = "".join(buf)
    print("identity: %s\n unambiguous: %s\n direct_from: %s\n, direct_to%s\n" % (identity, unambiguous, direct_from, direct_to))
    BUILDER.add_note(identity, unambiguous, direct_from, direct_to)

    BUILDER.export("Hello")
finally:
    BUILDER.close()
    shutil.rmtree(TMPDIR, ignore_errors=True)
