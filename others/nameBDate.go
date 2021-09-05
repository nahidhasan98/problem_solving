package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var name, bDate string

	fmt.Print("Please enter your name: ")

	//reading a line with spaces
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		name = scanner.Text()
	}

	fmt.Print("Please enter your birthdate like this format (2000-01-15): ")
	fmt.Scan(&bDate)

	fmt.Println("Your name is", name, "& your birthdate is", bDate)
}
