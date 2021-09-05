package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	flag := false

	for i := 0; i < len(s); i++ {
		if !flag && (string(s[i]) == "0" || i == len(s)-1) {
			flag = true
			continue
		} else {
			fmt.Print(string(s[i]))
		}
	}
	fmt.Println()
}
