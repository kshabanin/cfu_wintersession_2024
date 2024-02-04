#include <iostream>
#include <vector>

using namespace std;

int waterInValleys(vector<int>& heights) {
    int n = heights.size();
    if (n <= 2) return 0; // Если остров состоит из двух или менее столбцов, воды в низинах нет

    vector<int> leftMax(n), rightMax(n);

    // Находим максимальную высоту слева от каждого столбца
    leftMax[0] = heights[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    }

    // Находим максимальную высоту справа от каждого столбца
    rightMax[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], heights[i]);
    }

    int water = 0;

    // Для каждого столбца вычисляем количество воды в низине между ним и соседями
    for (int i = 0; i < n; ++i) {
        water += max(0, min(leftMax[i], rightMax[i]) - heights[i]);
    }

    return water;
}

int main() {
    int n;
    cout << "Введите количество столбцов острова: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Введите высоту каждого столбца, разделенную пробелами: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int water = waterInValleys(heights);
    cout << "Количество воды в низинах острова: " << water << endl;

    return 0;
}