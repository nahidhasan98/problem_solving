package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var x, y int
		fmt.Scan(&x, &y)

		res := 0

		if abs(x-y) <= 1 {
			res = x + y
		} else {
			temp := abs(x - y)
			res = (temp - 1) * 2

			if x > y {
				res += x - (temp - 1) + y
			} else {
				res += y - (temp - 1) + x
			}
		}

		fmt.Println(res)
	}
}
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 1
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 1 0 0 0 0 0 0
