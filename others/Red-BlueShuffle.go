package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n int
		fmt.Scan(&n)

		var r, b string
		fmt.Scan(&r, &b)

		rCount := 0
		bCount := 0

		for i := 0; i < len(r); i++ {
			if r[i] > b[i] {
				rCount++
			} else if r[i] < b[i] {
				bCount++
			}
		}
		if rCount > bCount {
			fmt.Println("RED")
		} else if rCount < bCount {
			fmt.Println("BLUE")
		} else {
			fmt.Println("EQUAL")
		}
	}
}
