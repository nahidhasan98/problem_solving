package main

import (
	"fmt"
	"math"
)

const max = 8000000

var prime [max]bool
var res []int

func sieve() {
	for i := 2; i < max; i++ {
		prime[i] = true
	}

	for i := 2; i <= int(math.Sqrt(max)); i++ {
		if prime[i] {
			for j := i * i; j < max; j += i {
				prime[j] = false
			}
		}
	}
}
func prepare() {
	res = append(res, 1) //filling up index 0
	for i := 2; i < max; i++ {
		if prime[i] {
			res = append(res, i)
		}
	}
}

func main() {
	sieve()
	prepare()

	var n int
	fmt.Scan(&n)

	fmt.Printf("%d\n", res[n])
}
