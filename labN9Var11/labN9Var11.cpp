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

double formul(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double formul(double a, int n, double b) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double formul(int n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double formul(double n, int k, double a, double b) {
    double h = (b - a) / n;
    double sum1 = 0;
    double sum2 = 0;
    int i = 1;
    do {
        sum2 += f(i);
        i += 2;
    } while (i <= 2 * k - 1);
    i = 2;
    do {
        sum2 += f(i);
        i += 2;
    } while (i <= 2 * k - 2);


    return (h / 3) * ((f(0) + f(2 * k)) + (4 * sum1) + 2 * sum2);
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

    double tochn = F(b) - f(a);
    n = k;
    std::cout << "Результаты для n = " << n << "\n";
    std::cout << "Левые прямоугольники: " << formul(a, b,n) << "\n";
    std::cout << "Правые прямоугольники: " << formul(a,n, b) << "\n";
    std::cout << "Метод трапеций: " << formul(n, a, b) << "\n";
    std::cout << "Метод Симпсона: " << formul(n,k, a, b) << "\n";
    std::cout << "Точное значение: " << tochn << "\n";
    n = 10 * k;
    std::cout << "Результаты для n = " << n << "\n";
    std::cout << "Левые прямоугольники: " << formul(a, b, n) << "\n";
    std::cout << "Правые прямоугольники: " << formul(a, n, b) << "\n";
    std::cout << "Метод трапеций: " << formul(n, a, b) << "\n";
    std::cout << "Метод Симпсона: " << formul(n, k, a, b) << "\n";
    std::cout << "Точное значение: " << tochn << "\n";

    return 0;
}