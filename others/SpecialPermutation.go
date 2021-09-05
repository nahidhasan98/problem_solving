package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n int
		fmt.Scan(&n)

		for i := 2; i <= n; i++ {
			fmt.Print(i, " ")
		}
		fmt.Println(1)
	}
}
