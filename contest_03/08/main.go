package main

import (
	"fmt"
	"os"
)

func findSingleNumber(numbers []int) int {
	result := 0

	// Используем XOR для поиска числа без пары
	for _, num := range numbers {
		result ^= num
	}

	return result
}

func main() {
	// Чтение количества чисел из первой строки ввода
	var n int
	fmt.Fscanf(os.Stdin, "%d\n", &n)

	// Чтение чисел из второй строки ввода
	numbers := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(os.Stdin, "%d", &numbers[i])
	}

	// Вызываем функцию поиска числа без пары
	result := findSingleNumber(numbers)

	// Выводим результат
	fmt.Println("Число без пары:", result)
}