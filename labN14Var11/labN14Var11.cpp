#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <string>

using Matrix = std::vector<std::vector<double>>;

double sumPositiveInEvenColumns(const Matrix& matrix) {
    double sum = 0;
    for (const auto& row : matrix)
        for (std::size_t column = 1; column < row.size(); column += 2)
            if (row[column] > 0) sum += row[column];
    return sum;
}

void printMatrix(const Matrix& matrix, const std::string& name) {
    std::cout << name << ":\n";
    for (const auto& row : matrix) {
        for (double value : row)
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << value;
        std::cout << '\n';
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int m, n;
    double k;
    std::cout << "Введите количество строк m (2..5): ";
    std::cin >> m;
    std::cout << "Введите количество столбцов n (2..6): ";
    std::cin >> n;
    std::cout << "Введите k (1.5..4.5): ";
    std::cin >> k;

    if (!std::cin || m < 2 || m > 5 || n < 2 || n > 6 || k < 1.5 || k > 4.5) {
        std::cout << "Некорректные входные данные.\n";
        return 1;
    }

    std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> distribution(-k, 2 * k);
    std::vector<Matrix> matrices(3, Matrix(m, std::vector<double>(n)));

    for (Matrix& matrix : matrices)
        for (auto& row : matrix)
            for (double& value : row) value = distribution(generator);

    for (std::size_t i = 0; i < matrices.size(); ++i)
        printMatrix(matrices[i], std::string(1, static_cast<char>('A' + i)));

    double minimum = sumPositiveInEvenColumns(matrices[0]);
    for (const Matrix& matrix : matrices)
        if (sumPositiveInEvenColumns(matrix) < minimum)
            minimum = sumPositiveInEvenColumns(matrix);

    std::cout << "\nМатрицы с минимальной суммой положительных элементов в четных столбцах: ";
    for (std::size_t i = 0; i < matrices.size(); ++i)
        if (sumPositiveInEvenColumns(matrices[i]) == minimum)
            std::cout << static_cast<char>('A' + i) << ' ';
    std::cout << "\nМинимальная сумма: " << minimum << '\n';

    return 0;
}
