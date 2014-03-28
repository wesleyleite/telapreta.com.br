#!/usr/bin/php5 
#
<?php

function CTAG($c) {
    switch ($c) {
        case "A":case "a":
        case "C":case "c":
        case "T":case "t":
        case "G":case "g":
            return 0;
            break;
        default:
            return 1;
            break;
    }
}

$FLAG=0;
$iStringTamanho=6;
if ($file = fopen("T2.txt", "r") ) {

    while(!feof($file)) {
        $FLAG=0;
        $string = explode("\t",fgets($file));
        for ( $i  = 0 ; $i < count($string) ; $i++ ) 
        {
            if (strlen($string[$i]) >= $iStringTamanho ) {
                if (CTAG($string[$i][0]) == 0 ) { 
                   for ( $j = 0 ; $j < strlen($string[$i]); $j++ ) {
                        if (CTAG($string[$i][$j]) == 1)
                            $FLAG=1;
                    }
                } else { $FLAG=1; }
            if ($FLAG==0)
                echo $string[$i]."\n";
            }
            $FLAG=0;
        }
    }
    fclose($file);
}

