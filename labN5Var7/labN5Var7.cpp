#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    char majuscule;
    std::cout << "Ведите одну из данных букв: P, K, T, B, L, R: ";
    if (!(std::cin >> majuscule))
        return 0;

    switch (majuscule) {
    case 'P':
        std::cout << "Paris\n";      break;
    case 'K':
        std::cout << "Kyiv\n";      break;
    case 'T':
        std::cout << "Tirana\n";    break;
    case 'B':
        std::cout << "Berlin\n";    break;
    case 'L':
        std::cout << "Lisbon\n";   break;
    case 'R':
        std::cout << "Rome\n";        break;
    default:
        std::cout << "Не правильно введена буква\n";
    }
    return 0;
}