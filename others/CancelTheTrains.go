package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n, m int
		fmt.Scan(&n, &m)

		var a = make(map[int]bool)
		var b = make(map[int]bool)
		var d int

		for i := 0; i < n; i++ {
			fmt.Scan(&d)
			a[d] = true
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&d)
			b[d] = true
		}

		counter := 0

		for key := range a {
			if b[key] {
				counter++
			}
		}
		fmt.Println(counter)
	}
}
