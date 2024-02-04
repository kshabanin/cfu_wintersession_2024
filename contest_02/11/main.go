package main

import "fmt"

const rows int = 9
const cols int = 9

// Функция isValidSudoku проверяет, является ли данная матрица решением судоку.
func isValidSudoku(board [rows][cols]int) bool {
	// Проверяем каждую строку и столбец
	for i := 0; i < rows; i++ {
		if !isValidRow(board, i) || !isValidColumn(board, i) {
			return false
		}
	}

	// Проверяем каждый блок 3x3
	for i := 0; i < rows; i += 3 {
		for j := 0; j < cols; j += 3 {
			if !isValidBlock(board, i, j) {
				return false
			}
		}
	}

	return true
}

// Функция isValidRow проверяет, является ли строка валидной для судоку
func isValidRow(board [rows][cols]int, row int) bool {
	seen := make(map[int]bool)
	for j := 0; j < cols; j++ {
		val := board[row][j]
		if val < 1 || val > 9 || (val != 0 && seen[val]) {
			return false
		}
		seen[val] = true
	}
	return true
}

// Функция isValidColumn проверяет, является ли столбец валидным для судоку
func isValidColumn(board [rows][cols]int, col int) bool {
	seen := make(map[int]bool)
	for i := 0; i < rows; i++ {
		val := board[i][col]
		if val < 1 || val > 9 || (val != 0 && seen[val]) {
			return false
		}
		seen[val] = true
	}
	return true
}

// Функция isValidBlock проверяет, является ли блок 3x3 валидным для судоку
func isValidBlock(board [rows][cols]int, startRow, startCol int) bool {
	seen := make(map[int]bool)
	for i := startRow; i < startRow+3; i++ {
		for j := startCol; j < startCol+3; j++ {
			val := board[i][j]
			if val < 1 || val > 9 || (val != 0 && seen[val]) {
				return false
			}
			seen[val] = true
		}
	}
	return true
}

func main() {
	var board [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &board[row][col])  // Считываем один символ
			board[row][col] -= '0'  // Преобразование символа в цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(board) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}