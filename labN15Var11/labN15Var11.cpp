#include <iostream>
#include <iomanip>
#include <random>
#include <vector>

int countInRow(const std::vector<double>& row, double left, double right) {
    int count = 0;
    for (double value : row)
        if (value >= left && value <= right) ++count;
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int m, n;
    double a, b;
    std::cout << "Введите количество строк m (5..10): ";
    std::cin >> m;
    std::cout << "Введите количество столбцов n (6..9): ";
    std::cin >> n;
    std::cout << "Введите a: ";
    std::cin >> a;
    std::cout << "Введите b: ";
    std::cin >> b;

    if (!std::cin || m < 5 || m > 10 || n < 6 || n > 9 || a > b) {
        std::cout << "Некорректные входные данные.\n";
        return 1;
    }

    double** matrix = new double*[m];
    for (int i = 0; i < m; ++i) matrix[i] = new double[n];

    std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> distribution(a, b);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) matrix[i][j] = distribution(generator);

    std::cout << "\nМатрица:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << matrix[i][j];
        std::cout << '\n';
    }

    double left = a + (b - a) / 8;
    double right = a + (b - a) / 2;
    std::cout << "\nНомера строк, в которых от двух до четырех элементов "
                 "лежат в диапазоне [a + (b - a) / 8, a + (b - a) / 2]: ";
    for (int i = 0; i < m; ++i) {
        int count = countInRow(std::vector<double>(matrix[i], matrix[i] + n), left, right);
        if (count >= 2 && count <= 4) std::cout << i + 1 << ' ';
    }
    std::cout << '\n';

    for (int i = 0; i < m; ++i) delete[] matrix[i];
    delete[] matrix;
    return 0;
}
