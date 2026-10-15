#include <iostream>
#include <iomanip>
#include <random>

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    double p;
    std::cout << "Введите размер массива n (1..10): ";
    std::cin >> n;
    std::cout << "Введите p (>=2): ";
    std::cin >> p;

    if (!std::cin || n < 1 || n > 10 || p < 2) {
        std::cout << "Некорректные входные данные.\n";
        return 1;
    }

    std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> distribution(0.5 * p, 3.5 * p);
    double values[10]{};

    for (int i = 0; i < n; ++i) values[i] = distribution(generator);

    double minimum = values[0];
    double maximum = values[0];
    for (int i = 1; i < n; ++i) {
        if (values[i] < minimum) minimum = values[i];
        if (values[i] > maximum) maximum = values[i];
    }

    double middle = (minimum + maximum) / 2;
    double sum = 0;
    std::cout << "\nМассив: ";
    for (int i = 0; i < n; ++i)
        std::cout << std::fixed << std::setprecision(2) << values[i] << ' ';

    std::cout << "\nИндексы элементов в диапазоне [min, (min + max) / 2]: ";
    for (int i = 0; i < n; ++i) {
        if (values[i] >= minimum && values[i] <= middle) {
            std::cout << i << ' ';
            sum += values[i];
        }
    }
    std::cout << "\nСумма этих элементов: " << sum << '\n';

    return 0;
}
