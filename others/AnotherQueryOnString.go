package main

import "fmt"

const maxSize = 1e5 + 10

var tree [maxSize * 3][30]int
var arr [maxSize]byte

func printTree(n int) {
	for i := 1; i < n*3; i++ {
		fmt.Println("node=", i)
		for j := 1; j <= 26; j++ {
			fmt.Print(string(byte(j + 96)))
		}
		fmt.Println()
		for j := 1; j <= 26; j++ {
			fmt.Print(tree[i][j])
		}
		fmt.Println()
	}
}
func update(node, rangeLeft, rangeRight, idx, ch int) {
	if rangeLeft > idx || rangeRight < idx {
		return
	}
	var oldChar int
	if rangeLeft == rangeRight {
		for i := 1; i <= 26; i++ {
			if tree[node][i] == 1 {
				oldChar = i
				break
			}
		}
		tree[node][arr[idx]] = 0
		tree[node][ch] = 1
		return
	}

	rangeMid := (rangeLeft + rangeRight) / 2
	left := node * 2
	right := (node * 2) + 1

	update(left, rangeLeft, rangeMid, idx, ch)
	update(right, rangeMid+1, rangeRight, idx, ch)

	tree[node][oldChar] = tree[left][oldChar] + tree[right][oldChar]

	// fmt.Println("node=", node, " ch=", ch, " lO=", tree[left][oldChar], " RO=", tree[right][oldChar])
	// fmt.Println(tree[node][oldChar])

	tree[node][ch] = tree[left][ch] + tree[right][ch]
}

func query(node, rangeLeft, rangeRight, l, r, ch int) int {
	if rangeLeft > r || rangeRight < l {
		return 0
	}
	if rangeLeft >= l && rangeRight <= r {
		return tree[node][ch]
	}

	rangeMid := (rangeLeft + rangeRight) / 2
	left := node * 2
	right := (node * 2) + 1

	a := query(left, rangeLeft, rangeMid, l, r, ch)
	b := query(right, rangeMid+1, rangeRight, l, r, ch)

	return a + b
}

func main() {
	var n, q int
	fmt.Scan(&n, &q)

	var s string
	fmt.Scan(&s)

	for i := 0; i < len(s); i++ {
		update(1, 1, n, i+1, int(s[i]-96))
		arr[i+1] = s[i]
	}

	// printTree(n)

	var comm, x, l, r int
	var ch string

	for t := 1; t <= q; t++ {
		fmt.Scan(&comm)

		if comm == 1 {
			fmt.Scan(&x, &ch)
			update(1, 1, n, x, int(ch[0]-96))
			arr[x] = ch[0]
			// printTree(n)
		} else {
			fmt.Scan(&l, &r, &ch)

			res := query(1, 1, n, l, r, int(ch[0]-96))
			fmt.Println(res)
		}
	}
}
