#include <iostream>
#include <vector>

bool isValidMove(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool canExitFromMaze(std::vector<std::vector<char>>& maze, int startRow, int startCol) {
    int currentRow = startRow;
    int currentCol = startCol;
    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (true) {
        if (!isValidMove(currentRow, currentCol, maze.size(), maze[0].size())) {
            return false;
        }

        char currentCell = maze[currentRow][currentCol];

        if (currentCell == '#') {
            return false;
        } else if (currentCell == 'E') {
            return true;
        }

        maze[currentRow][currentCol] = '#';

        for (int i = 0; i < 4; ++i) {
            int newRow = currentRow + moves[i][0];
            int newCol = currentCol + moves[i][1];

            if (isValidMove(newRow, newCol, maze.size(), maze[0].size()) &&
                maze[newRow][newCol] != '#') {
                currentRow = newRow;
                currentCol = newCol;
                break;
            }
        }
    }
}

int main() {
    int startRow, startCol, rows, cols;
    std::cout << "Введите начальную позицию (строка столбец): ";
    std::cin >> startRow >> startCol;

    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> rows >> cols;
    std::cin.ignore();  // Очищаем буфер ввода

    std::vector<std::vector<char>> maze(rows, std::vector<char>(cols));

    std::cout << "Введите лабиринт:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> std::noskipws >> maze[i][j]; // Отключаем пропуск пробелов
        }
        std::cin.ignore(); // Очищаем символ новой строки после каждой строки лабиринта
    }

    std::cout << "\nПытаемся найти выход из лабиринта...\n";

    bool exitFound = canExitFromMaze(maze, startRow, startCol);
    if (exitFound) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}