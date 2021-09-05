package main

import "fmt"

/**
 * Returns the total number of problems.
 *
 * @param n denotes the total number of problems in both computer
**/
func process(n int) (int, int) {
	// Implement this method
	var a = n / 2
	var b = n - a

	return a, b
}

/**
 * Takes care of the problem input and output.
**/
func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n int
		fmt.Scan(&n)

		a, b := process(n)
		fmt.Printf("%d %d\n", a, b)
	}
}
