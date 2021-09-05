package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)

		total := a + b + c
		div := total / 9

		if total%9 == 0 {
			if a >= div && b >= div && c >= div {
				fmt.Println("YES")
				continue
			}
		}
		fmt.Println("NO")
	}
}
