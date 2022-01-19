package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 0; t < test; t++ {
		var b [7]int
		for i := 0; i < 7; i++ {
			fmt.Scan(&b[i])
		}
		fmt.Println(b[0], b[1], b[6]-(b[0]+b[1]))
	}
}
