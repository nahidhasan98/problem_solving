package main

import (
	"fmt"
)

func main() {
	var A string
	fmt.Scan(&A)

	var B string
	fmt.Scan(&B)

	var countA [30]int
	var countB [30]int

	for i := 0; i < 30; i++ {
		countA[i] = 0
		countB[i] = 0
	}

	var index int

	for i := 0; i < len(A); i++ {
		index = int(A[i]) - 96
		countA[index]++
	}
	for i := 0; i < len(B); i++ {
		index = int(B[i]) - 96
		countB[index]++
	}

	var flag = 0
	for i := 0; i < 30; i++ {
		if countA[i] != countB[i] {
			flag = 1
			break
		}
	}

	if flag == 0 && len(A) == len(B) {
		fmt.Printf("Yes\n")
	} else if flag == 1 {
		fmt.Printf("No\n")
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
