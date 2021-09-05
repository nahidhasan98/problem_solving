package main

import "fmt"

func main() {
	x := []int{
		48, 96, 86, 68,
		57, 82, 63, 70,
		37, 34, 83, 27,
		19, 97, 9, 17,
	}

	var result = 1000000

	for i := 0; i < len(x); i++ {
		result = min(result, x[i])
	}

	fmt.Println("The smallest number among the array is: ", result)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
