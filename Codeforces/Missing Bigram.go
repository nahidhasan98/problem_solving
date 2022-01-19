package main

import "fmt"

func main() {
	var test int
	fmt.Scan(&test)

	for t := 0; t < test; t++ {
		var n int
		fmt.Scan(&n)

		var s []string
		for i := 0; i < n-2; i++ {
			var temp string
			fmt.Scan(&temp)
			s = append(s, temp)
		}

		res := s[0]
		for i := 1; i < n-2; i++ {
			if res[len(res)-1] == s[i][0] {
				res += string(s[i][1])
			} else {
				res += s[i]
			}
		}
		if len(res) < n {
			res += "a"
		}

		fmt.Println(res)
	}
}
