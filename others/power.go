package main

import "fmt"

var counter = 0

func power(base, pow int) int {
	counter++
	if pow == 1 {
		return base
	}

	temp := power(base, pow/2)

	if pow%2 == 0 {
		return temp * temp
	}
	return base * temp * temp
}

func main() {
	var base, pow int
	fmt.Scan(&base, &pow)

	fmt.Println(power(base, pow))
	fmt.Println(counter)
}
