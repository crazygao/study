#!/usr/bin/env python3
# coding: utf-8
""" Convert my note to items, eg  bent.md
    and I can use preview for preview
"""
import re
import sys

inF = open("src.txt", 'r', encoding='utf-8')
tempF = open("../template.md", 'r', encoding='utf-8')
for inFline in inF:
    concatstr = ""
    regex = re.compile(r"^(\D[^(\uff08\u0020)]+)", re.L|re.U)
    new_name = regex.match(inFline)
    if new_name is not None:
        print(new_name.group(1))
        item = new_name.group(1)
        new_Fname = item + u".md"
        outF = open(new_Fname, 'w', encoding='utf-8')
        outF.write(item + "\n")
        outF.write(tempF.read())
        tempF.seek(0)
        outF.close()
tempF.close()
inF.close()
