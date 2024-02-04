#include <iostream>
#include <cmath>

int main() {
    double pi_approx = std::sqrt(12.0) * (1 - 1.0 / 3 * 3 + 1.0 / 5 * 3 * 3 - 1.0 / 7 * 3 * 3 * 3 + 1.0 / 9 * 3 * 3 * 3 * 3 - 1.0 / 11 * 3 * 3 * 3 * 3 * 3);
    std::cout << "Приближенное значение числа π: " << pi_approx << std::endl;
    return 0;
}