package main

import "fmt"

func main() {
	var T int
	fmt.Scan(&T)

	for t := 1; t <= T; t++ {
		var n int
		fmt.Scan(&n)

		var s string
		fmt.Scan(&s)

		counter := 0

		for i := len(s) - 1; i >= 0; i-- {
			if string(s[i]) == ")" {
				counter++
			} else {
				break
			}
		}

		if counter > (n - counter) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
