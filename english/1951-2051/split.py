#!/usr/bin/env python3
""" Convert my note to items, eg  bent.md
    and I can use preview for preview 
"""
import re
import sys

inF = open("src.txt", 'r')
tempF = open("../template.md", 'r')
for inFline in inF:
    concatstr = ""
    regex = re.compile(r"^([a-zA-Z]+)")
    new_name = regex.match(inFline)
    if new_name is not None:
        print(new_name.group(1))
        item = new_name.group(1)
        new_Fname = item + ".md"
        outF = open(new_Fname, 'w')
        outF.write(item + "\n")
        outF.write(tempF.read())
        tempF.seek(0)
        outF.close()
tempF.close()
inF.close()
