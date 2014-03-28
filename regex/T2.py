#!/usr/bin/python
# -*- coding: utf-8 -*-
import re

file = open('T2.txt', 'r')



for Fstring in file.readlines():
    p = re.compile(r'[ctag]{6,}',re.IGNORECASE)
    res = p.findall(Fstring,0)
    print res
    res=""
