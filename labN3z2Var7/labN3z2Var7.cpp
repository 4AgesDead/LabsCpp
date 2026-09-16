#include <iostream>
#include <windows.h>
#include <clocale>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    int secall, sec, hour, minutes;

    std::cout << "Введите количество секунд ";
    std::cin >> secall;

    if (secall < 0) {
        std::cout << "Вы ввели неверное значение";
        return 0;
    }

    sec = secall % 60;
    secall = secall / 60;
    minutes = secall % 60;
    hour = secall / 60;

    std::cout << "У вас " << hour << " часов " << minutes << " минут " << sec << " секунд";
    return 0;
}