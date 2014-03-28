package main
import (
    "bufio"
    "fmt"
    "io"
    "log"
    "os"
    "regexp"
)
 
func main() {
    f, err := os.Open("T2.txt")
    if err != nil {
            log.Fatal(err)
    }
    re := regexp.MustCompile("([ctagCTAG]){6,}")

    bf := bufio.NewReader(f)
    for {
        switch line, err := bf.ReadString('\n'); err {
            case nil:
                fmt.Printf("%q\n",re.FindAllString(line,-1))
            case io.EOF:
                if line > "" {
                    fmt.Printf("%q\n",re.FindAllString(line,-1))
                }
                return
            default:
                log.Fatal(err)
        }
        
    }
}

