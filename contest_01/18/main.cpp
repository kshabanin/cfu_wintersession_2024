#include <iostream>
#include <string>

using namespace std;

string excelColumnName(int n) {
    string columnName = "";
    while (n > 0) {
        // Определяем символ для текущего разряда и добавляем его к имени столбца
        char digit = 'A' + (n - 1) % 26;
        columnName = digit + columnName;
        // Уменьшаем n на 1 (так как столбцы в Excel нумеруются с 1)
        n = (n - 1) / 26;
    }
    return columnName;
}

int main() {
    int n;
    cout << "Введите целочисленный номер столбца Excel: ";
    cin >> n;

    string columnName = excelColumnName(n);
    cout << "Имя столбца Excel для номера " << n << ": " << columnName << endl;

    return 0;
}