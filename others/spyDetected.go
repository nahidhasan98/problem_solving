package main

import "fmt"

func main() {
	var T int
	fmt.Scan(&T)

	for t := 0; t < T; t++ {
		var n, d int
		fmt.Scan(&n)

		var pos [101]int
		mp := make(map[int]int)

		for i := 0; i < n; i++ {
			fmt.Scan(&d)
			pos[d] = i + 1
			mp[d]++
		}

		for key, val := range mp {
			if val == 1 {
				fmt.Println(pos[key])
				break
			}
		}
	}
}
