#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    string input;
    cout << "Введите последовательность слов, разделенных пробелами (введите 'end' для завершения ввода):\n";

    // Считываем ввод, пока не встретится слово 'end'
    vector<string> words;
    while (cin >> input && input != "end") {
        words.push_back(input);
    }

    // Создаем отображение для подсчета частоты встречаемости слов
    map<string, int> wordFrequency;
    for (const string& word : words) {
        wordFrequency[word]++;
    }

    // Создаем множество для хранения слов, встречающихся более одного раза
    set<string> repeatedWords;
    for (const auto& entry : wordFrequency) {
        if (entry.second > 1) {
            repeatedWords.insert(entry.first);
        }
    }

    // Выводим повторяющиеся слова в лексикографическом порядке
    cout << "Повторяющиеся слова в алфавитном порядке: ";
    for (const string& word : repeatedWords) {
        cout << word << " ";
    }

    return 0;
}