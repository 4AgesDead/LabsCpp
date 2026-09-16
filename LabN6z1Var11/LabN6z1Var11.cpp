#include <iostream>
#include <cmath>
#include <windows.h>
#include <clocale>

int fx(double x) {
    double fx{ 7.3 * (x * x * x) + 1.5 / (x * x) - std::log(x * x - 1) };
    return fx;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");
    double x1, xm1, dx, x;
    std::cout << "введите xнач ";
    std::cin >> x1;
    std::cout << "введите xконец ";
    std::cin >> xm1;
    std::cout << "введите dx ";
    std::cin >> dx;
    if (dx <= 0 or x1 <= 1 or xm1 < 2 or xm1 == x1) {
        std::cout << "вы ввели не верное значение";
        return 0;
    }
    x = x1;
    long long y = fx(x);
    do {
        std::cout << std::left
            << std::endl
            << x
            << std::endl
            << y;

        x = x + dx;
        y = fx(x);
    } while (x < xm1);

    return 0;
}