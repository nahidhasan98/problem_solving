package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
)

func removeSpaces(s string) string {
	//removing extra spaces from begining & ending of line
	s = strings.TrimSpace(s)

	//replacing all consecutive spaces with a single space
	var reg = regexp.MustCompile(`[ ]{2,}`)
	s = reg.ReplaceAllString(s, " ")

	return s
}

func bigWord(s string) string {
	//replacing a long word (longer than 8 characters) with "#bigword"
	list := strings.Split(s, " ")
	s = ""

	for i := 0; i < len(list); i++ {
		if len(list[i]) > 8 {
			list[i] = "#bigword"
		}
		s += list[i]

		if i != len(list)-1 {
			s += " "
		}
	}
	return s
}

func formatString(s string, lineSize int) string {
	startIdx := 0

	for i := 0; i < len(s); i++ {
		rightBound := min(startIdx+lineSize, len(s)-1)

		//for the last segment/line
		if rightBound == len(s)-1 && rightBound-startIdx < 8 {
			break
		}

		for j := rightBound; j >= startIdx; j-- {
			if string(s[j]) == " " {
				s = s[:j] + "\n" + s[j+1:]
				startIdx = j + 1
				break
			}
		}
	}

	return s
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var s string

	//reading a line with spaces
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		s = scanner.Text()
	}

	s = removeSpaces(s)
	s = bigWord(s)

	//dividing into lines
	s = formatString(s, 8) //8 size + 1 newline character = total lineSize 9

	fmt.Printf("%s\n", s)
}
