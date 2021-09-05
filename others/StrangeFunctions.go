package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n string
		fmt.Scan(&n)

		fmt.Println(len(n))
	}
}
