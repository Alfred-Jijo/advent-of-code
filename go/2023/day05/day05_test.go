package main

import (
	"testing"
)

func TestPart1(t *testing.T) {
	result := Part1(inputTest)
	expected := 35
	if result != expected {
		t.Errorf("Result is incorrect, got: %d, want: %d.", result, expected)
	}
}

func TestPart2(t *testing.T) {
	t.Skip()
}

func BenchmarkPart1(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Part1(inputDay)
	}
}

// func BenchmarkPart2(b *testing.B) {
// 	for i := 0; i < b.N; i++ {
// 		Part2(inputDay)
// 	}
// }
