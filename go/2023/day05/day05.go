package main

import (
	_ "embed"
	"fmt"
	"time"
)

//go:embed input.txt
var inputDay string

func Part1(input string) int {
	return 0
}

func Part2(input string) int {
	return 0
}

func main() {
	fmt.Println("--2023 day 05 solution--")
	start := time.Now()
	fmt.Println("part1: ", Part1(inputDay))
	fmt.Println(time.Since(start))

	start = time.Now()
	fmt.Println("part2: ", Part2(inputDay))
	fmt.Println(time.Since(start))
}
