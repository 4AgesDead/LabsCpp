#include <iostream>
#include <cmath>
#include <clocale>
#include <limits>

double f(double* x) {
    double y = *x;
    return 4.0*std::pow(y,3) + 4.3 * y + 7.5;
}

void leftlimitation(double* a, double* b) {
    *a = (*a + *b) / 2.0;
}

void rightlimitation(double* a, double* b) {
    *b = (*a + *b) / 2.0;
}

void swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}

bool testlength(double* a, double* b) {
    return std::abs(*a - *b) <= 1.0;
}
bool opposite_signs(double x, double y) {
    return (x < 0.0 && y > 0.0) || (x > 0.0 && y < 0.0);
}

bool valid_sign(double a, double b, double eps) {
    double fa = f(&a);
    double fb = f(&b);

    if (!std::isfinite(fa) || !std::isfinite(fb)) {
        return false;
    }

    return std::abs(fa) < eps || std::abs(fb) < eps || opposite_signs(fa, fb);
}



int main() {
    std::setlocale(LC_ALL, "Russian");

    const double eps = 1e-6;
    double a, b;

    while (true) {
        std::cout << "Введите a: ";
        if (!(std::cin >> a)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Нужно ввести число.\n";
            continue;
        }

        std::cout << "Введите b: ";
        if (!(std::cin >> b)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Нужно ввести число.\n";
            continue;
        }

        if (!std::isfinite(a) || !std::isfinite(b)) {
            std::cout << "Нужно ввести конечные числа.\n";
            continue;
        }

        if (a > b) {
            swap(&a, &b);
        }

        if (!testlength(&a, &b)) {
            std::cout << "Длина отрезка должна быть не больше 1.\n";
            continue;
        }

        if (!valid_sign(a, b, eps)) {
            std::cout << "На отрезке нет изменения знака функции. Введите другой отрезок.\n";
            continue;
        }

        break;
    }

    // Если корень сразу оказался на границе отрезка
    if (std::abs(f(&a)) < eps) {
        std::cout << "Корень находится на конце отрезка: " << a << '\n';
        return 0;
    }

    if (std::abs(f(&b)) < eps) {
        std::cout << "Корень находится на конце отрезка: " << b << '\n';
        return 0;
    }

    // Метод дихотомии
    while (std::abs(b - a) > eps) {
        double c = (a + b) / 2.0;
        double fc = f(&c);

        if (std::abs(fc) < eps) {
            a = b = c;
            break;
        }

        double fa = f(&a);

        if (opposite_signs(fa, fc)) {
            rightlimitation(&a, &b);
        } else {
            leftlimitation(&a, &b);
        }
    }

    double root = (a + b) / 2.0;

    std::cout << "Итоговый отрезок: (" << a << ", " << b << ")\n";
    std::cout << "x: " << root << '\n';

    return 0;
}