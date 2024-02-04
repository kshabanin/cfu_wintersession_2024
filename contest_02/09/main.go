package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Функция isLucky определяет, является ли номер билета счастливым.
func isLucky(number string) bool {
	// Проверяем, что номер состоит ровно из 6 цифр
	if len(number) != 6 {
		return false
	}

	// Преобразуем строку в массив цифр
	digits := make([]int, 6)
	for i, char := range number {
		digit, err := strconv.Atoi(string(char))
		if err != nil {
			return false // Если символ не является цифрой, номер недействителен
		}
		digits[i] = digit
	}

	// Проверяем, является ли сумма первых трех цифр равной сумме последних трех
	return digits[0]+digits[1]+digits[2] == digits[3]+digits[4]+digits[5]
}

func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky(number[:len(number)-1]) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}