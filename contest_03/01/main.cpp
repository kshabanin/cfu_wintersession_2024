
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Ввод размерности первой последовательности
    int n;
    cin >> n;

    // Ввод элементов первой последовательности
    vector<int> sequence1(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence1[i];
    }

    // Ввод размерности второй последовательности
    int m;
    cin >> m;

    // Ввод элементов второй последовательности
    vector<int> sequence2(m);
    for (int i = 0; i < m; ++i) {
        cin >> sequence2[i];
    }

    // Объединение последовательностей
    vector<int> mergedSequence;
    merge(sequence1.begin(), sequence1.end(), sequence2.begin(), sequence2.end(), back_inserter(mergedSequence));

    // Вывод объединенной и отсортированной последовательности
    for (int i = 0; i < mergedSequence.size(); ++i) {
        cout << mergedSequence[i];
        if (i != mergedSequence.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}