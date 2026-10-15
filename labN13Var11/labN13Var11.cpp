#include <iostream>
#include <string>
#include <vector>

int countSymbols(const std::string& line, const std::string& symbols) {
    int count = 0;
    for (char symbol : line)
        if (symbols.find(symbol) != std::string::npos) ++count;
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите количество строк (1..12): ";
    std::cin >> n;
    if (!std::cin || n < 1 || n > 12) {
        std::cout << "Некорректное количество строк.\n";
        return 1;
    }

    std::cin.ignore(10000, '\n');
    std::vector<std::string> lines(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Строка " << i + 1 << ": ";
        std::getline(std::cin, lines[i]);
        if (lines[i].size() > 50) lines[i].resize(50);
    }

    std::cout << "\nСтроки, содержащие не более пяти символов из набора # ! @:\n";
    for (int i = 0; i < n; ++i) {
        if (countSymbols(lines[i], "#!@") <= 5)
            std::cout << i + 1 << ") " << lines[i] << '\n';
    }

    return 0;
}
