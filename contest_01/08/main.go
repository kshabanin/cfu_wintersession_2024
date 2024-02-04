package main

import (
	"fmt"
)

func main() {
	
	var num1, num2, num3 int

	// первое число
	fmt.Print("Введите первое целое число: ")
	fmt.Scan(&num1)

	// второе число
	fmt.Print("Введите второе целое число: ")
	fmt.Scan(&num2)

	// третье число
	fmt.Print("Введите третье целое число: ")
	fmt.Scan(&num3)

	// максимальное из трех чисел
	maxNum := num1
	if num2 > maxNum {
		maxNum = num2
	}
	if num3 > maxNum {
		maxNum = num3
	}

	// Вывод
	fmt.Printf("Максимальное из чисел %d, %d и %d: %d\n", num1, num2, num3, maxNum)
}