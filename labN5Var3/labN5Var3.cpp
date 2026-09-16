#include <iostream>
#include <windows.h>
#include <clocale>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");  

    int number;
    std::cout << "Введите десятичную цифру: ";
    if (!(std::cin >> number)) {          
        std::cout << "Вы ввели неверное значение\n";
        return 0;
    }

    switch (number) {
    case 0:  
        std::cout << "Вы ввели ноль\n";     break;
    case 1:  
        std::cout << "Вы ввели один\n";     break;
    case 2:  
        std::cout << "Вы ввели два\n";      break;
    case 3:  
        std::cout << "Вы ввели три\n";      break;
    case 4:  std::cout << "Вы ввели четыре\n";   break;
    case 5:  
        std::cout << "Вы ввели пять\n";     break;
    case 6:  
        std::cout << "Вы ввели шесть\n";    break;
    case 7:  
        std::cout << "Вы ввели семь\n";     break;
    case 8:  
        std::cout << "Вы ввели восемь\n";   break;
    case 9:  
        std::cout << "Вы ввели девять\n";   break;
    default: 
        std::cout << "Вы ввели неверное значение\n";
    }
    return 0;
}