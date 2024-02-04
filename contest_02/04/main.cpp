#include <iostream>
#include <tuple>

// Функция для нахождения наибольшего общего делителя (НОД)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для сокращения дроби и приведения ее к несократимому виду
std::tuple<int, int> reduce(int numerator, int denominator) {
    int divisor = gcd(numerator, denominator);
    return {numerator / divisor, denominator / divisor};
}

// Функция для нахождения наименьшего общего кратного (НОК)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Функция для нахождения НОК и множителей для приведения чисел к этому НОК
std::tuple<int, int, int> find_lcm(int a, int b) {
    int LCM = lcm(a, b);
    int multiplier_a = LCM / a;
    int multiplier_b = LCM / b;
    return {LCM, multiplier_a, multiplier_b};
}

int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1 >> m2 >> _ >> n2;

    // Сокращаем дроби перед выполнением операций
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    // Находим НОК и множители
    auto[lcm_val, c1, c2] = find_lcm(n1, n2);

    // Выполняем операцию сложения и сокращаем результат
    auto[result_numerator, result_denominator] = reduce(m1 * c1 + m2 * c2, lcm_val);

    // Выводим результат
    std::cout << result_numerator << '/' << result_denominator << std::endl;

    return 0;
}