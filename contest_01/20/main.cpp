#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isPossiblePermutation(int num1, int num2) {
    // Преобразуем числа в строки
    string strNum1 = to_string(num1);
    string strNum2 = to_string(num2);

    // Проверяем, имеют ли числа одинаковую длину
    if (strNum1.length() != strNum2.length()) {
        return false;
    }

    // Создаем отображения для подсчета частоты встречаемости цифр в каждом числе
    unordered_map<char, int> frequency1, frequency2;

    // Заполняем отображение для первого числа
    for (char digit : strNum1) {
        frequency1[digit]++;
    }

    // Заполняем отображение для второго числа
    for (char digit : strNum2) {
        frequency2[digit]++;
    }

    // Сравниваем отображения
    return frequency1 == frequency2;
}

int main() {
    int num1, num2;
    cout << "Введите два целых положительных числа, разделенных пробелом: ";
    cin >> num1 >> num2;

    // Проверяем возможность получения первого числа из второго перестановкой цифр
    if (isPossiblePermutation(num1, num2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}