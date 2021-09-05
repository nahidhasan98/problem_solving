package main

import "fmt"

/**
 * Returns the total number of problems.
 *
 * @param a denotes the number of problems in the first computer
 * @param b denotes the number of problems in the second computer
**/
func process(a, b int) int {
	// Implement this method
	return a + b
}

/**
 * Takes care of the problem input and output.
**/
func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var a, b int
		fmt.Scan(&a, &b)

		fmt.Printf("Case %d: %d\n", t, process(a, b))
	}
}
