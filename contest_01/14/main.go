package main

import "fmt"

func main() {
    var row, col int
    fmt.Print("Введите количество строк и столбцов (через пробел): ")
    fmt.Scan(&row, &col)

    // Вывод заголовка таблицы
    fmt.Print("    |")
    for j := 1; j <= col; j++ {
        fmt.Printf("%4d", j)
    }
    fmt.Println()
    fmt.Print("   ")
    for j := 0; j <= col; j++ {
        fmt.Print("----")
    }
    fmt.Println()

    // Вывод таблицы умножения
    for i := 1; i <= row; i++ {
        fmt.Printf("%2d |", i)
        for j := 1; j <= col; j++ {
            result := i * j
            fmt.Printf("%4d", result)
        }
        fmt.Println()
    }
}