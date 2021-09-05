package main

import (
	"fmt"
)

func currPosition(a, b, c int) int {
	if a == 1 {
		return 1
	} else if b == 1 {
		return 2
	}
	return 3
}

func main() {
	var a, b, c int
	fmt.Scanf("%d %d %d\n", &a, &b, &c)

	curr := currPosition(a, b, c)

	var s int
	fmt.Scanf("%d\n", &s)

	res := [4]int{0, 0, 0, 0}
	var p1, p2 int

	for i := 0; i < s; i++ {
		fmt.Scanf("%d %d\n", &p1, &p2)

		if curr == p1 {
			curr = p2
		} else if curr == p2 {
			curr = p1
		}
		res[curr]++
	}

	fmt.Printf("%d %d %d\n", res[1], res[2], res[3])
}
