#!/usr/bin/python
# -*- coding: utf-8 -*-
import re

T1 = U"Meu nome é Wesley Leite moro na Rua: ABCDEFGHIJ KLMNOPQR 3311, CEP: 19283-983 e Gosto de pêra"
regex = re.compile(r'Rua:.+ \d{5}.\d{3}')
res = regex.findall(T1)

print str(res)
