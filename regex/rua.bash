#!/bin/bash

T1="Meu nome é Wesley Leite moro na Rua: ABCDEFGHIJ KLMNOPQR 3311, CEP: 19283-983 e Gosto de pêra"
echo "${T1}" |
grep -Ewo 'Rua:.+([0-9]){5}.([0-9]){3}'

