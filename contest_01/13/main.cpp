#include <iostream>

int main() {
    int N;
    std::cout << "Введите целое положительное число N: ";
    std::cin >> N;

    int currentNumber = 1;
    int width = 1;

    while (currentNumber <= N) {
        for (int i = 0; i < width; ++i) {
            std::cout << currentNumber++ << " ";
            if (currentNumber > N) {
                break;
            }
        }

        std::cout << std::endl;

        width++;
    }

    return 0;
}