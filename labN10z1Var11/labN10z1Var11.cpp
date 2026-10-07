#include <iostream>

void swapValue(int a, int b) {
    int t = a; a = b; b = t;
}

void swapPtr(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}


void swapRef(int& a, int& b) {
    int t = a; a = b; b = t;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "функция swap\n";
    int a = 5, b = 8;
    std::cout << "До: a = " << a << ", b = " << b << "\n\n";

    int x = a, y = b;
    swapValue(x, y);
    std::cout << "1) Переменые x = " << x << ", y = " << y
              << "\n неправильно\n";

    x = a; y = b;
    swapPtr(&x, &y);
    std::cout << "2) Указатели:   x = " << x << ", y = " << y
              << "\n поменялись верно\n";

    x = a; y = b;
    swapRef(x, y);
    std::cout << "3) Ссылки:      x = " << x << ", y = " << y
              << "\n поменялись верно\n";
    
    return 0;
}
