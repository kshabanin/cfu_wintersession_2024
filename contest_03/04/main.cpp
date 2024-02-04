#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Ввод размерности первой последовательности
    int n;
    cin >> n;

    // Ввод слов первой последовательности
    vector<string> sequence1(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence1[i];
    }

    // Ввод размерности второй последовательности
    int m;
    cin >> m;

    // Ввод слов второй последовательности
    vector<string> sequence2(m);
    for (int i = 0; i < m; ++i) {
        cin >> sequence2[i];
    }

    // Сортировка обеих последовательностей
    sort(sequence1.begin(), sequence1.end());
    sort(sequence2.begin(), sequence2.end());

    // Используем алгоритм set_intersection для поиска пересечения последовательностей
    vector<string> intersection;
    set_intersection(sequence1.begin(), sequence1.end(), sequence2.begin(), sequence2.end(), back_inserter(intersection));

    // Вывод результата
    if (intersection.empty()) {
        cout << -1 << endl;
    } else {
        for (const string& word : intersection) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}