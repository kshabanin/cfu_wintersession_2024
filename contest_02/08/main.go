package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Функция isPalindrome определяет, является ли строка палиндромом с учетом условий задачи.
func isPalindrome(s string) bool {
	// Приводим все символы к нижнему регистру
	s = strings.ToLower(s)

	// Убираем пробелы и игнорируем спец символы
	var filteredStr strings.Builder
	for _, char := range s {
		if isAlphanumeric(char) {
			filteredStr.WriteRune(char)
		}
	}

	// Сравниваем оставшуюся строку с ее обратным порядком
	return filteredStr.String() == reverse(filteredStr.String())
}

// Функция проверяет, является ли символ буквой или цифрой
func isAlphanumeric(char rune) bool {
	return ('a' <= char && char <= 'z') || ('A' <= char && char <= 'Z') || ('0' <= char && char <= '9')
}

// Функция разворачивает строку
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isPalindrome(line[:len(line)-1]) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}