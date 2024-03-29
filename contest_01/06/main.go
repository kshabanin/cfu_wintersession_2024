package main

import "fmt"

func main() {
    // Ввод суммы для выдачи
    var N int
    fmt.Print("Введите сумму для выдачи: ")
    fmt.Scan(&N)

    // Инициализация переменных с количеством купюр каждого номинала
    var count5000, count1000, count500, count200, count100 int

    // Вычисление количества купюр каждого номинала
    count5000 = N / 5000
    N %= 5000

    count1000 = N / 1000
    N %= 1000

    count500 = N / 500
    N %= 500

    count200 = N / 200
    N %= 200

    count100 = N / 100

    // Вывод результатов
    fmt.Println("Количество купюр номиналом 5000 рублей:", count5000)
    fmt.Println("Количество купюр номиналом 1000 рублей:", count1000)
    fmt.Println("Количество купюр номиналом 500 рублей:", count500)
    fmt.Println("Количество купюр номиналом 200 рублей:", count200)
    fmt.Println("Количество купюр номиналом 100 рублей:", count100)
}