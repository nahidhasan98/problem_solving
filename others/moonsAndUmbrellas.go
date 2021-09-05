package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var x, y int
		fmt.Scan(&x, &y)

		var s string
		fmt.Scan(&s)

		//replacing all consecutive spaces with a single space
		var reg = regexp.MustCompile(`[?]{2,}`)
		s = reg.ReplaceAllString(s, "?")

		if len(s) > 1 && string(s[0]) == "?" {
			s = s[1:]
		}
		if len(s) > 1 && string(s[len(s)-1]) == "?" {
			s = s[:len(s)-1]
		}

		for i := 1; i < len(s)-1; i++ {
			if string(s[i]) == "?" {
				if string(s[i-1]) == "C" {
					s = strings.Replace(s, "?", "C", 1)
				} else if string(s[i-1]) == "J" {
					s = strings.Replace(s, "?", "J", 1)
				}
			}
		}

		//fmt.Println(s)
		sum := 0

		for i := 0; i < len(s)-1; i++ {
			if string(s[i]) == "C" && string(s[i+1]) == "J" {
				sum += x
			} else if string(s[i]) == "J" && string(s[i+1]) == "C" {
				sum += y
			}
		}

		fmt.Printf("Case #%d: %d\n", t, sum)
	}
}
