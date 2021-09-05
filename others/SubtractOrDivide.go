package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n int
		fmt.Scan(&n)

		if n == 1 {
			fmt.Println(0)
		} else if n == 2 {
			fmt.Println(1)
		} else if n == 3 {
			fmt.Println(2)
		} else if n%2 == 0 {
			fmt.Println(2)
		} else if n%2 != 0 {
			fmt.Println(3)
		}
	}
}
