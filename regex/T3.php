#!/usr/bin/php5 
#
<?php

if ($file = fopen("T2.txt", "r") ) {

    while(!feof($file)) {
        $string = fgets($file);
        preg_match_all('@[ctag]{23}@i',
        "$string",
        $matches);
        print_r($matches);
    }
    fclose($file);
}

