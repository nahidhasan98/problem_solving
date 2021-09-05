package main

import (
	"fmt"
	"reflect"
)

func main() {
	fmt.Println("Please enter the size of array:")

	var size int
	fmt.Scanf("%d", &size)

	var x = make([]int64, size)

	fmt.Println(x)
	fmt.Println(reflect.TypeOf(x).Kind().String())
}
