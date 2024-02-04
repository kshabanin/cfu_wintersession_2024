package main

import (
	"fmt"
)

func main() {
	// Задаем три вопроса
	fmt.Println("Умеет ли существо плавать? (Да/Нет)")
	swims := getUserInput()

	fmt.Println("Есть ли у него крылья? (Да/Нет)")
	hasWings := getUserInput()

	fmt.Println("Длинная ли у него шея? (Да/Нет)")
	longNeck := getUserInput()

	// Определяем животное
	animal := identifyAnimal(swims, hasWings, longNeck)

	// Вывод
	fmt.Printf("По вашим ответам, это похоже на: %s\n", animal)
}

// Функция проверки ответа
func getUserInput() string {
	var userInput string
	for {
		fmt.Scanln(&userInput)
		if userInput == "Да" || userInput == "Нет"  {
			break
		} else {
			fmt.Println("Пожалуйста, введите только 'Да' или 'Нет'. (С большой буквы)")
		}
	}
	return userInput
}

// Функция для определения животного
func identifyAnimal(swims, hasWings, longNeck string) string {
	switch {
	case swims == "Нет" && hasWings == "Нет" && longNeck == "Нет":
		return "Кот"
	case swims == "Нет" && hasWings == "Нет" && longNeck == "Да":
		return "Жираф"
	case swims == "Нет" && hasWings == "Да" && longNeck == "Нет":
		return "Курица"
	case swims == "Нет" && hasWings == "Да" && longNeck == "Да":
		return "Страус"
	case swims == "Да" && hasWings == "Нет" && longNeck == "Нет":
		return "Дельфин"
	case swims == "Да" && hasWings == "Нет" && longNeck == "Да":
		return "Плезиозавры"
	case swims == "Да" && hasWings == "Да" && longNeck == "Нет":
		return "Пингвин"
	case swims == "Да" && hasWings == "Да" && longNeck == "Да":
		return "Утка"
	default:
		return "Неопределенное животное"
	}
}