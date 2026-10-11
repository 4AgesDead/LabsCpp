#include <iostream>

void F(int N, int& First, int& Last) {
    Last = N % 10;
    while (N / 10 != 0) {
        N/=10
    }
    First = N;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N;
    std::cout << "Введите натуральное число N: ";
    std::cin >> N;

    int First, Last;
    F(N, First, Last);
    std::cout << "Старшая цифра числа " << N << ": " << First << "\n";
    std::cout << "Младшая цифра числа " << N << ": " << Last << "\n";

    return 0;
}
