#include <iostream>

void flip(int* N) {
    int rev = 0;
    while (*N > 0) {
        rev = rev * 10 + *N % 10;
        *N /= 10;
    }
    *N = rev;
}

void flip(int& N) {
    int rev = 0;
    while (N > 0) {
        rev = rev * 10 + N % 10;
        N /= 10;
    }
    N = rev;
}

int flip(int N) {
    int rev = 0;
    while (N > 0) {
        rev = rev * 10 + N % 10;
        N /= 10;
    }
    return rev;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N;
    std::cout << "Введите натуральное число N: ";
    std::cin >> N;

    std::cout << "\nВарианты функции flip для N = " << N << "\n";

    int x = N;
    flip(&x);
    std::cout << "1) void flip(int*)= " << x << "\n";

    int y = N;
    void (*fref)(int&) = flip;
    fref(y);                      
    std::cout << "2) void flip(int&)= " << y << "\n";

    int z = flip(N + 0);           
    std::cout << "3) int  flip(int)= " << z << ", исходное N = " << N << "\n";

    return 0;
}
