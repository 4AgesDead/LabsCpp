#include <iostream>
#include <cmath>
int main()
{
    setlocale(LC_ALL, "Russian");

    double x1, y1, x2, y2, x3, y3, x4, y4, AB, BC, CD, DA, P;

    std::cout << "введите x1 "; std::cin >> x1;  
    std::cout << "введите y1 "; std::cin >> y1;
    std::cout << "введите x2 "; std::cin >> x2;
    std::cout << "введите y2 "; std::cin >> y2;
    std::cout << "введите x3 "; std::cin >> x3;
    std::cout << "введите y3 "; std::cin >> y3;
    std::cout << "введите x4 "; std::cin >> x4;
    std::cout << "введите y4 "; std::cin >> y4;

    AB = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    BC = std::sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    CD = std::sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
    DA = std::sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
    P = AB + BC + CD + DA;

    std::cout << "Периметр четырехугольника: " << P;
    return 0;
}