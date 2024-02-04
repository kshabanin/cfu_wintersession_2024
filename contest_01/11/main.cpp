#include <iostream>
#include <cmath>

int main() {
    // Координаты точек A, B и C 
    double xA, xB, xC;

    // Ввод координат точек
    std::cout << "Введите координату точки A: ";
    std::cin >> xA;

    std::cout << "Введите координату точки B: ";
    std::cin >> xB;

    std::cout << "Введите координату точки C: ";
    std::cin >> xC;

    // Расстояния от точек B и C до A
    double distanceB = std::abs(xB - xA);
    double distanceC = std::abs(xC - xA);

    // Определение, какая из точек (B или C) ближе к A
    if (distanceB < distanceC) {
        std::cout << "Точка B ближе к A на расстоянии: " << distanceB << std::endl;
    } else {
        std::cout << "Точка C ближе к A на расстоянии: " << distanceC << std::endl;
    }

    return 0;
}