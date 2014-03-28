#!/usr/bin/php5

<?php

$T1="Meu nome é Wesley Leite moro na Rua: ABCDEFGHIJ KLMNOPQR 3311, CEP: 19283-983 e Gosto de pêra";

preg_match('@Rua:.+(\d){5}.(\d){3}@',
  $T1,
  $matches);

print($matches[0]);


