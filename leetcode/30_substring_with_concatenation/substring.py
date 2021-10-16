from typing import List
import re
class Item:
    word = ""
    length = 0
    # position in the words list
    position = 0
    def __init__(self, _word, _length, _position):
        word = _word
        length = _length
        position = _position
class MatchItem:
    # where is your head in the string
    position = 0
    # how long is your current matched string
    matchedLength = 0
    # which string index do you match in the words
    howMatch = []
    # you have at most two position to match the next, what are they?
    headMatch = [] # [{int, string}]
    def __init__(self, s, Item):
class Solution:
    wordsLength = 0
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # Item -> length, head.
        # MatchItem -> Position, length, howMatch?, headMatch[{int, headChar}] (len < 2)

        # Step 1 create the dictionary of words. hash is ok but I just use the first char.
        wordDict = {}
        baseWord = Item(words[0], 0)
        for word in words[1:]:
            wordDict[word[0]] = [Item(word, len(word))]

        # Step 2 first round select first word and find all its position, create MatchItem
        baseWordLength = len(baseWord)
        sindex = 0
        MatchItemArray = []
        while (sindex = s.find(baseWord, sindex)) != -1:
            MatchItemArray.push(MatchItem(sindex))
        
    # Step 2 I This is a recursive function.
    def oneRoundFromStart
    

s= Solution()
s.findSubstring("aa", ["aa", "bb"])
        
