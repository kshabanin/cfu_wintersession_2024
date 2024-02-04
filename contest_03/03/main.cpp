
#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Функция для определения приоритета операторов
int getPriority(char op) {
    switch (op) {
        case '^': return 4; // Увеличиваем приоритет степени
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Функция для преобразования в обратную польскую нотацию
string toReversePolishNotation(string expression) {
    stack<char> operators;
    string result;

    for (char& c : expression) {
        if (isdigit(c)) {
            result += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += ' ';
                result += operators.top();
                operators.pop();
            }
            operators.pop(); // Удаляем открывающую скобку из стека
        } else {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(c)) {
                if (operators.top() == '^' && c == '^') 
                    break;
                result += ' ';
                result += operators.top();
                operators.pop();
            }
            operators.push(c);
            result += ' ';
        }
    }

    while (!operators.empty()) {
        result += ' ';
        result += operators.top();
        operators.pop();
    }

    return result;
}

int main() {
    cout << "Введите арифметическое выражение (без пробелов): ";

    string expression;
    getline(cin, expression);

    string result = toReversePolishNotation(expression);
    cout << result << endl;

    return 0;
}