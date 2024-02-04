#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Ввод числа слов в тексте
    int n;
    cin >> n;
    cin.ignore(); // Игнорируем символ новой строки

    // Ввод текста
    string text;
    getline(cin, text);

    // Создание потока для разделения текста на слова
    istringstream iss(text);

    // Хранение частоты каждого слова
    unordered_map<string, int> wordFrequency;

    // Переменная для хранения максимальной частоты
    int maxFrequency = 0;

    // Чтение слов из текста и подсчет частоты
    string word;
    while (iss >> word) {
        wordFrequency[word]++;
        maxFrequency = max(maxFrequency, wordFrequency[word]);
    }

    // Вывод слов с максимальной частотой в лексикографическом порядке
    vector<string> mostFrequentWords;
    for (const auto& entry : wordFrequency) {
        if (entry.second == maxFrequency) {
            mostFrequentWords.push_back(entry.first);
        }
    }

    // Сортировка и вывод результатов
    sort(mostFrequentWords.begin(), mostFrequentWords.end());
    for (int i = 0; i < mostFrequentWords.size(); ++i) {
        cout << mostFrequentWords[i];
        if (i != mostFrequentWords.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}