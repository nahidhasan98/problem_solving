package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	var stack string

	for i := 0; i < len(s); i++ {
		if s[i] == ')' && len(stack) > 0 && stack[len(stack)-1] == '(' {
			stack = strings.TrimSuffix(stack, "(")
		} else if s[i] == '}' && len(stack) > 0 && stack[len(stack)-1] == '{' {
			stack = strings.TrimSuffix(stack, "{")
		} else if s[i] == ']' && len(stack) > 0 && stack[len(stack)-1] == '[' {
			stack = strings.TrimSuffix(stack, "[")
		} else {
			stack += string(s[i])
		}
	}

	if len(stack) == 0 {
		fmt.Printf("Yes\n")
	} else {
		fmt.Printf("No\n")
	}
}
