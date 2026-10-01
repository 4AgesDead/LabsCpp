#include <iostream>
#include <cmath>

const double pi {std::numbers::pi};    
    
double f(double(x)){
        return 2.3*std::pow(x,3)+std::sin(x)+0.5;
    }
    
double F(double(x)){
        return 0.575*std::pow(x,4)-std::cos(x)+0.5*x;
    }
    
    
double triangleleft(double n, double a, double b){
        double h=(b-a)/n;
        double sum =0;
        int i = 0;
        do{
            sum+=f(i);
            i++;
            
        }while(i<n);
        return h*sum;
}   
double triangleright(double n, double a, double b){
        double h=(b-a)/n;
        double sum =0;
        int i = 1;
        do{
            sum+=f(i);
            i++;
            
        }while(i<=n);
        return h*sum;
}   

double traps(double n, double a, double b){
        double h=(b-a)/n;
        int i = 0;
        double sum =(f(i)+f(n))/2;
        do{
            sum+=f(i);
            i++;
            
        }while(i<n);
        return sum;
}   
double Simpson(double n, double k, double a, double b){
        double h=(b-a)/n;
        double sum1 = 0;
        double sum2 = 0;
        int i =1;
        do{
            sum2 += f(i);
            i+=2;
        }while (i<=2*k-1);
        i =2;
        do{
            sum2 += f(i);
            i+=2;
        }while (i<=2*k-2);
        
        
        return (h/3)*((f(0)+f(2*k))+(4*sum1)+2*sum2) ;
}   
    

int main()
{
    setlocale(LC_ALL, "Russian");
    double k, a, b;
    std::cout << "Введите нижний предел a, максимально возможный " << pi / 12<<' ';
    std::cin >> a;
    std::cout << "Введите верхний предел b, максимально возможный " << pi / 2<<' ';
    std::cin >> b;
    std::cout << "Введите k: ";
    std::cin >> k;
    double tochn = F(b)-f(a);
    double n = k;
    std::cout << "Результаты для n = " << n <<"\n";
    std::cout << "Левые прямоугольники: " << triangleleft(n,a, b) <<"\n";
    std::cout << "Правые прямоугольники: " << triangleright(n, a, b) <<"\n";
    std::cout << "Метод трапеций: " << traps(n, a, b) <<"\n";
    std::cout << "Метод Симпсона: " << Simpson(n,k, a, b) <<"\n";
    std::cout << "Точное значение: " << tochn <<"\n";
    n = 10*k;
    std::cout << "Результаты для n = " << n <<"\n";
    std::cout << "Левые прямоугольники: " << triangleleft(n,a, b) <<"\n";
    std::cout << "Правые прямоугольники: " << triangleright(n, a, b) <<"\n";
    std::cout << "Метод трапеций: " << traps(n, a, b) <<"\n";
    std::cout << "Метод Симпсона: " << Simpson(n,k, a, b) <<"\n";
    std::cout << "Точное значение: " << tochn <<"\n";
    
    return 0;
}