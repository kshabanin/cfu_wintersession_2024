package main

import (
	"fmt"
	"os"
)

func findPair(numbers []int, target int) (int, int) {
	seen := make(map[int]bool)

	for _, num := range numbers {
		complement := target - num

		// Проверяем, есть ли complement в множестве уже просмотренных чисел
		if seen[complement] {
			return complement, num
		}

		// Добавляем текущее число в множество просмотренных
		seen[num] = true
	}

	// Если нет подходящей пары, возвращаем два нуля
	return 0, 0
}

func main() {
	// Чтение размера последовательности и числа X из первой строки ввода
	var n, target int
	fmt.Fscanf(os.Stdin, "%d %d\n", &n, &target)

	// Чтение последовательности из второй строки ввода
	numbers := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(os.Stdin, "%d", &numbers[i])
	}

	// Поиск пары чисел сумма которых равна X
	resultA, resultB := findPair(numbers, target)

	// Переставляем числа, если нужно, чтобы выводить в порядке возрастания
	if resultA > resultB {
		resultA, resultB = resultB, resultA
	}

	// Вывод результата
	fmt.Printf("%d %d\n", resultA, resultB)
}