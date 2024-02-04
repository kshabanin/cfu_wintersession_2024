#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// Функция для подсчета количества единиц в строке
int countOnes(const std::string& str) {
    return std::count(str.begin(), str.end(), '1');
}

// Функция сравнения для использования в std::sort
bool compare(const std::string& a, const std::string& b) {
    int countA = countOnes(a);
    int countB = countOnes(b);

    if (countA > countB) {
        return true;  // Сортируем по убыванию количества единиц
    } else if (countA < countB) {
        return false;
    } else {
        // В случае равного количества единиц, сортируем по возрастанию значения
        return a < b;
    }
}

int main() {
    int count;
    std::cin >> count;

    std::vector<std::string> nums(count);
    for (auto& line : nums)
        std::cin >> line;

    std::sort(nums.begin(), nums.end(), compare);

    for (auto& line : nums)
        std::cout << line << ' ';

    return 0;
}