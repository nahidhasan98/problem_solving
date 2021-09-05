package main

import (
	"fmt"
	"math"
)

var prime [1000001]int64

func sieve() {
	for i := 2; i < len(prime); i++ {
		if prime[i] == 0 {
			for j := i * 2; j < len(prime); j += i {
				prime[j] = 1
			}
		}
	}
}

func main() {
	sieve()

	n := 600851475143

	for i := 2; i < int(math.Sqrt(float64(n))); i++ {
		if prime[i] == 0 && n%i == 0 {
			n /= i
		}
	}

	fmt.Println(n)
}
