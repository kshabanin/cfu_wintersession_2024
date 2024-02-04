package main

import "fmt"

// Функция fill заполняет игровое поле сапёра по заданным правилам
func fill(maze [][]int) {
	rows := len(maze)
	cols := len(maze[0])

	// Перебираем каждую ячейку
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			// Если текущая ячейка заминирована, пропускаем
			if maze[i][j] == -1 {
				continue
			}

			// Считаем количество мин вокруг текущей ячейки
			minesCount := 0
			for x := -1; x <= 1; x++ {
				for y := -1; y <= 1; y++ {
					nx := i + x
					ny := j + y

					// Проверяем, что координаты в пределах поля
					if nx >= 0 && nx < rows && ny >= 0 && ny < cols {
						// Увеличиваем счетчик мин, если нашли мину
						if maze[nx][ny] == -1 {
							minesCount++
						}
					}
				}
			}

			// Заполняем текущую ячейку количеством мин вокруг
			maze[i][j] = minesCount
		}
	}
}

func main() {
	var rows, cols int
	fmt.Scanf("%d %d\n", &rows, &cols)

	// Создаём срез и заполняем его данными о расположении мин
	maze := make([][]int, rows, rows)
	for i := range maze {
		maze[i] = make([]int, cols, cols)
		for j := range maze[i] {
			fmt.Scanf("%d", &maze[i][j])
		}
	}

	// Заполняем игровое поле подсказками
	fill(maze)

	// Выводим на экран
	for _, row := range maze {
		for _, cell := range row {
			fmt.Printf("%3d", cell)
		}
		fmt.Println()
	}
}