#include <iostream>
#include <cmath>
#include <numbers>
#include <cstdlib>

const double pi{ std::acos(-1.0)};

double f(double x) {
    return 2.3 * std::pow(x, 3) + 3.5 * std::sin(x) + 0.5;
}

double F(double x) {
    return 0.575 * std::pow(x, 4) - 3.5 * std::cos(x) + 0.5 * x;
}

double triangleleft(int n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double triangleright(int n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double traps(int n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double Simpson(int n, double a, double b) {
    if (n % 2 != 0) return -1;

    double h = (b - a) / n;

    double sum1 = 0.0;
    for (int i = 1; i <= n - 1; i += 2) {
        sum1 += f(a + i * h);
    }

    double sum2 = 0.0;
    for (int i = 2; i <= n - 2; i += 2) {
        sum2 += f(a + i * h);
    }

    return (h / 3.0) * (f(a) + f(b) + 4.0 * sum1 + 2.0 * sum2);
}


int main() {
    setlocale(LC_ALL, "Russian");
    double a, b;
    int k, n;
    std::cout << "Введите нижний предел a (не больше " << pi / 12 << "): ";
    std::cin >> a;
    std::cout << "Введите верхний предел b (не больше " << pi / 2 << "): ";
    std::cin >> b;
    std::cout << "Введите k: ";
    std::cin >> k;

    double tochn = F(b) - F(a);
    n = k;
    std::cout << "Результаты для n = " << n << "\n";
    std::cout << "Левые прямоугольники: " << triangleleft(n, a, b) << "\n";
    std::cout << "Правые прямоугольники: " << triangleright(n, a, b) << "\n";
    std::cout << "Метод трапеций: " << traps(n, a, b) << "\n";
    std::cout << "Метод Симпсона: " << Simpson(n, a, b) << "\n";
    std::cout << "Точное значение: " << tochn << "\n";
    n = 10*k;
    std::cout << "Результаты для n = " << n << "\n";
    std::cout << "Левые прямоугольники: " << triangleleft(n, a, b) << "\n";
    std::cout << "Правые прямоугольники: " << triangleright(n, a, b) << "\n";
    std::cout << "Метод трапеций: " << traps(n, a, b) << "\n";
    std::cout << "Метод Симпсона: " << Simpson(n, a, b) << "\n";
    std::cout << "Точное значение: " << tochn << "\n";

    return 0;
}
