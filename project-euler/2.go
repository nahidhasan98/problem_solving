package main

import "fmt"

var fibo []int

func generateFibo() {
	pre, next, curr := 1, 2, 0
	fibo = append(fibo, pre)
	fibo = append(fibo, next)

	for {
		curr = pre + next
		fibo = append(fibo, curr)

		pre = next
		next = curr

		if curr > 4000000 {
			break
		}
	}
}

func getSum() int {
	sum := 0
	for i := 0; i < len(fibo); i++ {
		if fibo[i]%2 == 0 {
			sum += fibo[i]
		}
	}
	return sum
}

func main() {
	generateFibo()

	fmt.Println(getSum())
}
