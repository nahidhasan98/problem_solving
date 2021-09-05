package main

import "fmt"

func main() {
	var T int
	fmt.Scan(&T)

	for t := 0; t < T; t++ {
		var n int
		fmt.Scan(&n)

		var s string
		fmt.Scan(&s)

		mp := make(map[string]bool)
		mp[string(s[0])] = true

		var flag bool

		for i := 1; i < len(s); i++ {
			if mp[string(s[i])] && string(s[i]) != string(s[i-1]) {
				fmt.Println("NO")
				flag = true
				break
			}
			mp[string(s[i])] = true
		}

		if !flag {
			fmt.Println("YES")
		}
	}
}
