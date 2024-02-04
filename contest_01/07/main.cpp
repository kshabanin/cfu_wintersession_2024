#include <iostream>

int main() {

    int num1, num2;

    // Ввод первого числа
    std::cout << "Введите первое число: ";
    std::cin >> num1;

    // Ввод второго числа
    std::cout << "Введите второе число: ";
    std::cin >> num2;

    // Вычисление максимального
    int maxNum = (num1 > num2) ? num1 : num2;

    // Вывод
    std::cout << "Максимально число из " << num1 << " и " << num2 << " : " << maxNum << std::endl;

    return 0;
}