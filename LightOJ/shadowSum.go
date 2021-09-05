package main

import "fmt"

func abs(n int) int {
	if n < 0 {
		return n * (-1)
	}
	return n
}

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n int
		fmt.Scan(&n)

		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}

		mp := make(map[int]bool, n)
		sum := 0

		for i := n - 1; i >= 0; i-- {
			if !mp[abs(a[i])] {
				sum += a[i]
				mp[abs(a[i])] = true
			}
			//fmt.Printf("i=%d, sum=%d\n", i, sum)
		}

		fmt.Printf("Case %d: %d\n", t, sum)
	}

}
