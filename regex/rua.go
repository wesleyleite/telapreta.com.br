package main

import (
    "fmt"
    "regexp"
)

func main() {
    T1 := "Meu nome é Wesley Leite moro na Rua: ABCDEFGHIJ KLMNOPQR 3311, CEP: 19283-983 e Gosto de pêra"
    re := regexp.MustCompile("Rua:.+([0-9]){5}.([0-9]){3}")
    fmt.Printf("%q\n", re.FindString(T1))
}

