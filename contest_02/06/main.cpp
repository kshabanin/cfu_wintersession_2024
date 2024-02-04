#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

Student make_student(const std::string& line) {
    size_t pos = line.find(';');
    std::string name = line.substr(0, pos);
    std::string group = line.substr(pos + 1);

    return {name, group};
}

bool is_upper(const Student& s1, const Student& s2) {
    // Извлекаем числовое значение из строки group
    int group_num1 = std::stoi(s1.group.substr(6));
    int group_num2 = std::stoi(s2.group.substr(6));

    if (group_num1 != group_num2) {
        return group_num1 < group_num2;
    }

    return s1.name < s2.name;
}

void print(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Empty list!" << std::endl;
        return;
    }

    auto it = students.begin();
    while (it != students.end()) {
        std::cout << "Group: " << it->group << std::endl;

        // Печатаем фамилии студентов из текущей группы
        while (it != students.end() && it->group == (it - 1)->group) {
            std::cout << "- " << it->name << std::endl;
            ++it;
        }
        // Переход к следующей группе
        while (it != students.end() && it->group != (it - 1)->group) {
            ++it;
        }
    }
}

int main() {
    int count;
    std::cin >> count;
    std::cin.ignore(1);

    std::vector<Student> students(count);
    for (auto& student : students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }

    std::sort(students.begin(), students.end(), is_upper);

    print(students);

    return 0;
}