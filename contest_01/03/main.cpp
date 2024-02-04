#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "Введите два числа через пробел: ";
    cin >> a >> b;

    if (b != 0) {
        double result = a / b;
        cout << "Результат деления: " << result << endl;
    }
    else {
        cout << "Ошибка: деление на ноль!" << endl;
    }

    return 0;
}