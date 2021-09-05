package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	var s string
	var res int = 0

	for i := 1; i <= n; i++ {
		fmt.Scan(&s)

		if string(s[0]) == "+" || string(s[2]) == "+" {
			res++
		} else {
			res--
		}
	}

	fmt.Println(res)
}
