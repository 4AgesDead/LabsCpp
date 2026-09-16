#include <iostream>
#include <cmath>
#include <windows.h>
#include <clocale>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    double x, y;
    std::cout << "введите координату x ";
    std::cin >> x;
    std::cout << "введите координату y ";
    std::cin >> y;

    if (x > 0)
    {
        double len{ std::sqrt(x * x + y * y) };
        if (len <= 3)
        {
            std::cout << "точка находится в обозначенной зоне";
            return 0;
        }
        else
        {
            std::cout << "точка не находится в обозначенной зоне";
            return 0;
        }
    }
    else
    {
        if ((x < 3 and y < 3) and (-x > std::abs(y)))
        {
            std::cout << "точка не находится в обозначенной зоне";
            return 0;
        }
        else
        {
            std::cout << "точка находится в обозначенной зоне";
            return 0;
        }
    }
}