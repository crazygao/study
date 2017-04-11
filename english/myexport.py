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

    def export(self, fname):
        export = AnkiPackageExporter(self.collection)
        export.exportInto(fname)

    def close(self):
        self.collection.close()
