package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n int
		var s string

		fmt.Scan(&n, &s)

		counter := 0
		for i := n - 1; i >= 0; i-- {
			if s[i] == ')' {
				counter++
			} else {
				break
			}
		}

		if counter > (n - counter) {
			fmt.Printf("Yes\n")
		} else {
			fmt.Printf("No\n")
		}
	}
}
