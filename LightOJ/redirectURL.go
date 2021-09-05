package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var s string
		fmt.Scan(&s)

		if string(s[4]) != "s" {
			s = s[0:4] + "s" + s[4:]
		}

		fmt.Printf("Case %d: %s\n", t, s)
	}

}
