#include <iostream>
#include <cmath> 

int main() {
    
    double a, b, c;

    //Первое значение
    std::cout << "Введите длину первого катета: ";
    std::cin >> a;

    //второе значение
    std::cout << "Введите длину второго катета: ";
    std::cin >> b;

    //вычисление
    c = sqrt(a * a + b * b);

    //вывод
    std::cout << "Длина гипотенузы: " << c << std::endl;

    return 0;
}