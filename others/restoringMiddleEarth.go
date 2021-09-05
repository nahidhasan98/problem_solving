package main

import (
	"fmt"
	"sort"
)

func abs(n int) int {
	if n < 0 {
		return n * (-1)
	}
	return n
}

func main() {
	var test int
	fmt.Scanf("%d\n", &test)

	for t := 1; t <= test; t++ {
		var n, k int
		fmt.Scanf("%d %d\n", &n, &k)

		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &a[i])
		}
		fmt.Scanf("")

		sort.Ints(a)
		sum := make([]int64, n)

		sum[0] = int64(a[0])
		for i := 1; i < n; i++ {
			sum[i] = sum[i-1] + int64(a[i])
		}

		var res int64
		for i := n - 1; i > 0; i -= k - 1 {
			res += sum[i]
		}

		fmt.Printf("Case %d: %v\n", t, res)
	}

}
