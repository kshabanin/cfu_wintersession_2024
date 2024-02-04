package main

import (
	"fmt"
)

func smoothData(data []int) []float64 {
	n := len(data)
	smoothed := make([]float64, n)

	// Начинаем с индекса 1 и заканчиваем на индексе n - 2,
	// чтобы оставить первый и последний элементы без изменений
	for i := 1; i < n-1; i++ {
		smoothed[i] = float64(data[i-1]+data[i]+data[i+1]) / 3.0
	}

	// Первый и последний элементы остаются без изменений
	smoothed[0] = float64(data[0])
	smoothed[n-1] = float64(data[n-1])

	return smoothed
}

func main() {
	var n int
	fmt.Print("Введите длину последовательности (n ≥ 2): ")
	fmt.Scan(&n)

	if n < 2 {
		fmt.Println("Ошибка: длина последовательности должна быть не менее 2.")
		return
	}

	// Инициализация среза для хранения введенных значений
	data := make([]int, n)

	// Ввод значений от пользователя
	fmt.Print("Введите последовательность измерений через пробел: ")
	for i := 0; i < n; i++ {
		fmt.Scan(&data[i])
	}

	// Вызываем функцию для сглаживания данных
	smoothedData := smoothData(data)

	// Выводим сглаженные данные
	fmt.Print("Сглаженная последовательность: ")
	for _, val := range smoothedData {
		fmt.Printf("%.10f ", val)
	}
}