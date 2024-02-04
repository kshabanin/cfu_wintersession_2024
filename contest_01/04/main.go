package main

import (
 "fmt"
)

func main() {
 var a, b float64
 fmt.Print("Введите два числа через пробел: ")
 _, err := fmt.Scan(&a, &b)
 if err != nil {
  fmt.Println("Ошибка: введите два корректных числа")
  return
 }

 result := a * b
 fmt.Printf("Результат умножения: %f\n", result)
}