package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var T int
	fmt.Scan(&T)

	for t := 0; t < T; t++ {
		var arr [4]int

		for i := 0; i < 4; i++ {
			fmt.Scan(&arr[i])
		}

		f1 := max(arr[0], arr[1])
		l1 := min(arr[0], arr[1])

		f2 := max(arr[2], arr[3])
		l2 := min(arr[2], arr[3])

		if f1 > l2 && f2 > l1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
