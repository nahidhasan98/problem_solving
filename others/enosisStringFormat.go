package main

import (
	"fmt"
)

func main() {
	s := "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."

	result := formatString(s, 20)

	fmt.Println(result)
}

func formatString(s string, lineSize int) string {
	startIdx := 0

	for i := 0; i < len(s); i++ {
		rightBound := min(startIdx+lineSize, len(s)-1)

		//fmt.Println(s[i])

		for j := rightBound; j >= max(0, startIdx); j-- {
			if string(s[j]) == " " {
				s = s[:j] + "\n" + s[j+1:]
				startIdx = j + 1
				fmt.Println(startIdx, rightBound)
				break
			}
		}
	}

	return s
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
