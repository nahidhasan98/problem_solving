package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n, k int
		fmt.Scan(&n, &k)

		res := ""
		currChar := 0

		for len(res) < n {
			for j := 1; j <= k; j++ {
				res += string(byte(currChar + 97))
				if len(res) == n {
					break
				}
			}
			currChar++
			currChar %= 3
		}
		fmt.Println(res)
	}
}

//97 98 99  100 101 102  103 104
