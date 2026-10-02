#include <iostream>
#include <cmath>
#include <numbers>
#include <cstdlib>

const double pi{ std::numbers::pi };

double f(double x) {
    return 2.3 * std::pow(x, 3) + std::sin(x) + 0.5;
}

double F(double x) {
    return 0.575 * std::pow(x, 4) - std::cos(x) + 0.5 * x;
}

double triangleleft(double n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double triangleright(double n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double traps(double n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double Simpson(double k, double a, double b) {
    // 2k subintervals
    double h = (b - a) / (2 * k);
    double sum1 = 0; // odd indices
    double sum2 = 0; // even indices (excluding endpoints)
    for (int i = 1; i < 2 * k; ++i) {
        if (i % 2 == 1) sum1 += f(a + i * h);
        else sum2 += f(a + i * h);
    }
    return (h / 3) * ((f(a) + f(b)) + 4 * sum1 + 2 * sum2);
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, k;
    std::cout << "Введите нижний предел a (не больше " << pi / 12 << "): ";
    std::cin >> a;
    std::cout << "Введите верхний предел b (не больше " << pi / 2 << "): ";
    std::cin >> b;
    std::cout << "Введите k: ";
    std::cin >> k;

    double tochn = F(b) - f(a);

    for (double n : {k, 10 * k}) {
        std::cout << "Результаты для n = " << n << "\n";
        std::cout << "Левые прямоугольники: " << triangleleft(n, a, b) << "\n";
        std::cout << "Правые прямоугольники: " << triangleright(n, a, b) << "\n";
        std::cout << "Метод трапеций: " << traps(n, a, b) << "\n";
        std::cout << "Метод Симпсона: " << Simpson(k, a, b) << "\n";
        std::cout << "Точное значение: " << tochn << "\n";
    }

    return 0;
}