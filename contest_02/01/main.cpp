#include <iostream>
#include <cmath>

bool is_prime(int n) {
    // Проверка на минимальное простое число
    if (n <= 1) {
        return false;
    }

    // Проверка наличия делителей до корня из числа
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false; // Число делится на i, следовательно, не простое
        }
    }

    return true; // Если не найдено делителей, то число простое
}

int main() {
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;

    return 0;
}