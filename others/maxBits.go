package main

import (
	"fmt"
	"strconv"
)

func decToBin(n int64) string {
	//res := strconv.FormatInt(n, 2)
	s := ""
	var r int64

	for {
		if n != 0 {
			r = n % 2
			s += strconv.Itoa(int(r))
			n /= 2
		} else {
			break
		}
	}

	res := ""
	for i := len(s) - 1; i >= 0; i-- {
		res += string(s[i])
	}

	return res
}

func binToDec(s string) int64 {
	//res, _ := strconv.ParseInt(s, 2, 64)
	var res, powerTwo int64 = 0, 1

	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '1' {
			res += powerTwo
		}

		powerTwo *= 2
	}

	return res
}

func powerTwo(power int) int64 {
	var res int64 = 1

	for i := 1; i <= power; i++ {
		res *= 2
	}

	return res

}

func isAllDigitsOne(r int64) bool {
	s1 := decToBin(r)
	s2 := decToBin(r + 1)

	if len(s1) == len(s2) {
		return false //r is like: 1011
	}
	return true //r is like: 1111
}

func replaceZeroWithOneFromLast(s string) string {
	for i := len(s) - 1; i >= 0; i-- {
		if string(s[i]) == "0" {
			s = s[:i] + "1" + s[i+1:]
			break
		}
	}
	return s
}

func main() {
	var T int
	fmt.Scan(&T)

	for t := 1; t <= T; t++ {
		var l, r int64
		fmt.Scan(&l, &r)

		if (l == r) || isAllDigitsOne(r) {
			fmt.Println(r)
			continue
		}

		s1 := decToBin(r)
		maxPossibleDigit := len(s1)

		if l == 0 && r > 0 {
			maxPossibleDigit--                             //lower the digit by 1 . like: 1011 -> 111 (4 digit to 3 digit)
			var ans int64 = powerTwo(maxPossibleDigit) - 1 //for 3 digit, 2^3 = 8 . 8 - 1 = 7 which is 111
			fmt.Println(ans)

			continue
		}

		//in normal case like: l & r both are > 0 and l != r
		s2 := decToBin(l)
		minPossibleDigit := len(s2)

		if minPossibleDigit != maxPossibleDigit {
			maxPossibleDigit--                             //lower the digit by 1 of r
			var ans int64 = powerTwo(maxPossibleDigit) - 1 //for 3 digit, 2^3 = 8 . 8 - 1 = 7 which is 111
			fmt.Println(ans)
		} else {
			s := decToBin(l)
			curr := l
			var ans int64

			for {
				if curr <= r {
					ans = curr
					s = replaceZeroWithOneFromLast(s) // 1001101001 -> 1001101011
					curr = binToDec(s)
				} else {
					break
				}
			}
			fmt.Println(ans)
		}
	}
}

/*
00000000 =  0 log2() = undefined
00000001 =  1 log2() = 0 + 1 = 1
00000010 =  2 log2() = 1 + 1 = 2
00000011 =  3 log2() = 1 + 1 = 2
00000100 =  4 log2() = 2 + 1 = 3
00000101 =  5 log2() = 2 + 1 = 3
00000110 =  6 log2() = 2 + 1 = 3
00000111 =  7 log2() = 2 + 1 = 3
00001000 =  8 log2() = 3 + 1 = 4
00001001 =  9 log2() = 3 + 1 = 4
00001010 = 10 log2() = 3 + 1 = 4
00001011 = 11 log2() = 3 + 1 = 4
00001100 = 12 log2() = 3 + 1 = 4
00001101 = 13 log2() = 3 + 1 = 4
00001110 = 14 log2() = 3 + 1 = 4
00001111 = 15 log2() = 3 + 1 = 4
00010000 = 16 log2() = 4 + 1 = 5
*/

/*
576460752303423488 1000000000000000000
576460752303423488 936463254927549952
*/
