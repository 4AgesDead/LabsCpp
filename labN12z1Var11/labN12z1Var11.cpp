#include <iostream>
#include <random>

int main() {
    setlocale(LC_ALL, "Russian");

    int m, k;
    std::cout << "Введите размер массивов m (1..7): ";
    std::cin >> m;
    std::cout << "Введите k (4..8): ";
    std::cin >> k;

    if (!std::cin || m < 1 || m > 7 || k <= 3 || k >= 9) {
        std::cout << "Некорректные входные данные.\n";
        return 1;
    }

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(k, 3 * k);
    int arrays[4][7]{};

    for (int i = 0; i < 4; ++i) {
        std::cout << "array" << i + 1 << ": ";
        for (int j = 0; j < m; ++j) {
            arrays[i][j] = distribution(generator);
            std::cout << arrays[i][j] << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "\nСумма элементов, кратных 5:\n";
    for (int i = 0; i < 4; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j)
            if (arrays[i][j] % 5 == 0) sum += arrays[i][j];
        std::cout << "array" << i + 1 << " = " << sum << '\n';
    }

    return 0;
}
