package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n int
		fmt.Scan(&n)

		var a = make([]int, n)

		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}

		for i, j := 0, n-1; i <= j; i, j = i+1, j-1 {
			if i+1 == j {
				fmt.Printf("%d %d\n", a[i], a[j])
			} else if i == j {
				fmt.Printf("%d\n", a[i])
			} else {
				fmt.Printf("%d %d ", a[i], a[j])
			}
		}
	}
}
