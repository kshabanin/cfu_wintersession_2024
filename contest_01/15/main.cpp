#include <iostream>
#include <string>

std::string compressRLE(const std::string& input) {
    std::string compressed;

    // Обработка пустой строки
    if (input.empty()) {
        return compressed;
    }

    char currentChar = input[0];
    int count = 1;

    for (int i = 1; i < input.length(); i++) {
        if (input[i] == currentChar) {
            // Увеличиваем счетчик повторений
            count++;
        } else {
            // Добавляем символ и количество повторений к сжатой строке
            compressed += currentChar;
            if (count > 1) {
                compressed += std::to_string(count);
            }

            // Сбрасываем счетчик для нового символа
            currentChar = input[i];
            count = 1;
        }
    }

    // Добавляем последний символ и количество повторений
    compressed += currentChar;
    if (count > 1) {
        compressed += std::to_string(count);
    }

    return compressed;
}

int main() {
    std::string input;
    std::cout << "Введите строку из заглавных латинских букв A-Z: ";
    std::cin >> input;

    std::string compressed = compressRLE(input);

    std::cout << "Сжатая строка: " << compressed << std::endl;

    return 0;
}