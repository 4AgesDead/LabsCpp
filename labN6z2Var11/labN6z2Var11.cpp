#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "");

    double x;
    std::cout << "Введите значение x: ";
    if (!(std::cin >> x) || x == 0) {
        std::cout << "Некорректный ввод\n";
        return 1;
    }

    double fx = x * x - std::log(x * x);
    double sum = 0;
    unsigned long long  n = 0;

    do {
        ++n;
        sum += 1.0 / n;
    } while (sum < fx);

    std::cout << n << std::endl;
    return 0;
}