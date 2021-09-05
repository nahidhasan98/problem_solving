package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	mx := 0
	var arr []string
	var s string

	for i := 0; i < n; i++ {
		fmt.Scan(&s)

		if len(s) == 2 { //if given string is ba
			s += "a"
		} else if len(s)%2 == 0 { //means number of a's is odd
			s = strings.TrimSuffix(s, "a")
		}
		mx = max(mx, len(s))
		arr = append(arr, s)
	}

	for i := 0; i < n; i++ {
		for j := 1; j <= (mx-len(arr[i]))/2; j++ {
			fmt.Printf(" ")
		}
		fmt.Printf("%s\n", arr[i])
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
