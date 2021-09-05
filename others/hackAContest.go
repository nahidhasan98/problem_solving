package main

import (
	"fmt"
	"sort"
)

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n, m int
		fmt.Scan(&n, &m)
		time := make([]int, n)
		c := make([]int, m)

		for i := 0; i < n; i++ {
			fmt.Scan(&time[i])
		}

		for i := 0; i < m; i++ {
			fmt.Scan(&c[i])
		}

		sort.Ints(time)
		sort.Ints(c)

		sum, idx, counter := 0, 0, 0

		for i := 0; i < n; i++ {
			if c[idx] == 1 {
				sum += time[i] + (counter * 20)
				counter = 0
				idx++
			} else {
				c[idx]--
				counter++
			}
		}
		fmt.Printf("Case %d: %d\n", t, sum)
	}
}
