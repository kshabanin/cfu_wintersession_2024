package main

import "fmt"

// Функция shift выполняет сдвиг элементов переданного среза на steps позиций вправо или влево.
func shift(arr []int, steps int) {
	length := len(arr)

	// Обработка отрицательных steps (сдвиг влево)
	if steps < 0 {
		steps = (length + steps%length) % length
	}

	// Создаем временный срез для хранения результатов сдвига
	result := make([]int, length)

	// Выполняем сдвиг
	for i := 0; i < length; i++ {
		result[(i+steps)%length] = arr[i]
	}

	// Копируем результаты обратно в оригинальный срез
	copy(arr, result)
}

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}