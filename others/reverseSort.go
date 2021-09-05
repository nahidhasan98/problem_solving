package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n int
		fmt.Scan(&n)

		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}

		sum := 0
		for i := 0; i < n-1; i++ {
			minVal := 9999
			minIdx := 0

			for j := i; j < n; j++ {
				if a[j] < minVal {
					minVal = a[j]
					minIdx = j
				}
			}

			for j, k := i, minIdx; j <= i+((minIdx-i)/2); j++ {
				a[j], a[k] = a[k], a[j]
				k--
			}

			sum += minIdx - i + 1
			fmt.Println(i, sum)
		}
		fmt.Printf("Case #%d: %d\n", t, sum)
	}
}

/*
2 4 6 7 5 3 1

7 6 5 4 3 2 1
1 2 3 4 5 6 7 <--

1 2 3 4 5 6 7
*/
