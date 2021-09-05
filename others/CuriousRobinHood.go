package main

import "fmt"

const mxSize = 1e5 + 5

var tree = make([]int, mxSize*3)

func main() {
	var test int
	fmt.Scan(&test)

	for t := 1; t <= test; t++ {
		var n, q int
		fmt.Scan(&n, &q)

		initArray := make([]int, n+1)

		for i := 1; i <= n; i++ {
			fmt.Scan(&initArray[i])
			update(1, 1, n, i, initArray[i])
		}

		fmt.Printf("Case %d:\n", t)

		var comm, i, j, v int
		for k := 0; k < q; k++ {
			fmt.Scan(&comm)

			if comm == 1 {
				fmt.Scan(&i)
				fmt.Printf("%d\n", query(1, 1, n, i, j))
				update(1, 1, n, i, -1)
			} else if comm == 2 {
				fmt.Scan(&i, &v)
				update(1, 1, n, i+1, v)
			} else {
				fmt.Scan(&i, &j)
				fmt.Printf("%d\n", query(1, 1, n, i+1, j+1))
			}
		}
	}
}

func update(node, rangeLeft, rangeRight, idx, value int) {
	if rangeLeft == rangeRight {
		if value < 0 {
			tree[node] = 0
		} else {
			tree[node] += value
		}
		return
	}

	rangeMid := (rangeLeft + rangeRight) / 2
	left := node * 2
	right := (node * 2) + 1

	update(left, 1, rangeMid, idx, value)
	update(right, rangeMid+1, rangeRight, idx, value)

	tree[node] = tree[left] + tree[right]
}
func query(node, rangeLeft, rangeRight, i, j int) int {
	if i > rangeRight || j < rangeLeft {
		return 0
	}
	if i <= rangeLeft && j >= rangeRight {
		return tree[node]
	}

	rangeMid := (rangeLeft + rangeRight) / 2
	left := node * 2
	right := (node * 2) + 1

	a := query(left, 1, rangeMid, i, j)
	b := query(right, rangeMid+1, rangeRight, i, j)

	return a + b
}
