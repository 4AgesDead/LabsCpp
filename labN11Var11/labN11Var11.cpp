#include <iostream>
#include <cmath>

double f(double* x) {
    return 4 * std::pow(*x, 3) + 4.3 * *x + 7.5;
}

void leftlimitation(double* a, double* b) {
    *a = (*b + *a) / 2;
}

void rightlimitation(double* a, double* b) {
    *b = (*b + *a) / 2;
}

void swap(double* a, double* b) {
    double t;
    t = *a;*a = *b;*b = t;
}
int testlenght(double* a, double* b) {
    double lenght = std::abs(*a - *b);
    if (lenght > 1) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b;
    std::cout << "Введите a ";std::cin >> a;
    std::cout << "Введите b ";std::cin >> b;
   if(testlenght(&a, &b)!=1){do{
        std::cout << "\nВы ввели не верные значения b";
        std::cout << "\nВведите a ";std::cin >> a;
        std::cout << "Введите b ";std::cin >> b;
    } while (testlenght(&a, &b)!=1);}
    
    std::cout<<a<<' '<<b;
    double c= a+b/2;
    do{
        if (f(&a)<0 and f(&b)>0){
           leftlimitation(&a,&b);
        }
        else{
            rightlimitation(&a,&b);
        }
    }while(f(&a)*f(&c)!=0);
    return 0;
}