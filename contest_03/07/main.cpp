#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Открываем файл на чтение
    ifstream file("data.txt");
    
    // Проверяем, открыт ли файл успешно
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    // Читаем текст из файла
    string word;
    vector<string> words;
    while (file >> word && word != "stopword") {
        words.push_back(word);
    }

    // Закрываем файл
    file.close();

    // Вводим слово-цель (target)
    string target;
    cin >> target;

    // Создаем словарь для хранения следующих слов после target и их частот
    unordered_map<string, int> nextWordFreq;

    // Итерируем по всем словам и ищем следующие слова после target
    for (size_t i = 0; i < words.size() - 1; ++i) {
        if (words[i] == target) {
            // Получаем следующее слово
            string nextWord = words[i + 1];
            // Увеличиваем частоту этого слова
            nextWordFreq[nextWord]++;
        }
    }

    // Проверяем, было ли найдено хоть одно слово после target
    if (nextWordFreq.empty()) {
        cout << "-" << endl; // Нет следующих слов
    } else {
        // Сортируем слова по убыванию частоты, а затем лексикографически
        vector<pair<string, int>> sortedWords(nextWordFreq.begin(), nextWordFreq.end());
        sort(sortedWords.begin(), sortedWords.end(),
            [](const pair<string, int>& a, const pair<string, int>& b) {
                if (a.second != b.second) {
                    return a.second > b.second; // Сортировка по частоте
                } else {
                    return a.first < b.first; // Лексикографическая сортировка
                }
            }
        );

        // Выводим до 3-х слов
        for (size_t i = 0; i < min(sortedWords.size(), size_t(3)); ++i) {
            cout << sortedWords[i].first;
            if (i < 2 && i < sortedWords.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}