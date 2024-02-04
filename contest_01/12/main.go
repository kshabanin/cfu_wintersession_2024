package main

import (
	"fmt"
)

func collatzSteps(x int) int {
	steps := 0
	for x != 1 {
		if x%2 == 0 {
			x = x / 2
		} else {
			x = 3*x + 1
		}
		steps++
	}
	return steps
}

func main() {
	// Ввод начального значения X
	var x int
	fmt.Print("Введите начальное значение X: ")
	fmt.Scan(&x)

	// Подсчет шагов до достижения 1
	steps := collatzSteps(x)

	// Вывод результата
	fmt.Printf("Для X=%d количество шагов до достижения 1: %d\n", x, steps)
}