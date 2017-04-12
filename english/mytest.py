import os, tempfile
import sys

sys.path.append("/Users/philip/study/anki/")

from anki import Collection as aopen
from anki.exporting import *
from anki.importing import Anki2Importer
from tests.shared import getEmptyCol

deck = None
ds = None

with open("template.html", mode='r', buffering=1, encoding="utf-8") as FIN:
    DOM = FIN.readlines()

def setup1():
    global deck
    deck = getEmptyCol()
    f = deck.newNote()
    f['Front'] = DOM[0];
    
    f['Back'] = "".join(DOM[1:]);
    #f.tags = ["tag", "tag2"]
    deck.addNote(f)
    # with a different deck
    #f = deck.newNote()
    #f['Front'] = "baz"; f['Back'] = "qux"
    #f.model()['did'] = deck.decks.id("new deck")
    #deck.addNote(f)


def test_export_anki():
    setup1()
    # create a new deck with its own conf to test conf copying
    did = deck.decks.id("test")
    dobj = deck.decks.get(did)
    #confId = deck.decks.confId("newconf")
    #conf = deck.decks.getConf(confId)
    #conf['new']['perDay'] = 5
    #deck.decks.save(conf)
    #deck.decks.setConf(dobj, confId)
    # export
    e = AnkiExporter(deck)
    fd, newname = tempfile.mkstemp(prefix="ankitest", suffix=".anki2")
    newname = str(newname)
    #os.close(fd)
    #os.unlink(newname)
    e.exportInto(newname)
    # exporting should not have changed conf for original deck
    #conf = deck.decks.confForDid(did)
    #assert conf['id'] != 1
    # connect to new deck
    d2 = aopen(newname)
    assert d2.cardCount() == 1
    print(newname)
    os.close(fd)
    # as scheduling was reset, should also revert decks to default conf
    #did = d2.decks.id("test", create=False)
    #assert did
    #conf2 = d2.decks.confForDid(did)
    #assert conf2['new']['perDay'] == 20
    #dobj = d2.decks.get(did)
    # conf should be 1
    #assert dobj['conf'] == 1
    # try again, limited to a deck
    #fd, newname = tempfile.mkstemp(prefix="ankitest", suffix=".anki2")
    #newname = str(newname)
    #os.close(fd)
    #os.unlink(newname)
    #e.did = 1
    #e.exportInto(newname)
    #d2 = aopen(newname)
    #assert d2.cardCount() == 1
test_export_anki()
