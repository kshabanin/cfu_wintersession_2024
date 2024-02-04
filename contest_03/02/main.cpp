#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string text) {
    stack<char> brackets;

    for (char& c : text) {
        if (c == '(' || c == '{' || c == '[') {
            brackets.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (brackets.empty()) {
                return false;
            } else if ((c == ')' && brackets.top() != '(') || (c == '}' && brackets.top() != '{') || (c == ']' && brackets.top() != '[')) {
                return false;
            } else {
                brackets.pop();
            }
        }
    }

    return brackets.empty(); // Валидно, если стек пустой после обхода всего текста
}

int main() {
    cout << "Введите текст, содержащий скобки (для завершения введите '!'): " << endl;

    string text;
    getline(cin, text, '!');

    if (isValid(text)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}