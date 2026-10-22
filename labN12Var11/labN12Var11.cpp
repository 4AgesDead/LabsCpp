#include <iostream>
#include <vector>
#include <clocale>
#include <random>

/// функция для вывода массивов 
void print(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void printsum5(const std::vector<int>& arr) {
    int sum;
    for (int x : arr) {
        if (x%5==0){
            sum+=x;
        }
    }
    std::cout <<sum<< std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int k;
    
    std::cout << "Введите значение k (3,9): ";
    std::cin >> k;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 7);
    std::uniform_int_distribution<int> distrib2(k, k * 3);

    ///создание массивов
    int num = distrib(gen);
    std::vector<int> arr1(num);
    for (int i = 0; i < num; i++) {
        arr1[i] = distrib2(gen);
    }

    num = distrib(gen);
    std::vector<int> arr2(num);
    for (int i = 0; i < num; i++) {
        arr2[i] = distrib2(gen);
    }

    num = distrib(gen);
    std::vector<int> arr3(num);
    for (int i = 0; i < num; i++) {
        arr3[i] = distrib2(gen);
    }

    num = distrib(gen);
    std::vector<int> arr4(num);
    for (int i = 0; i < num; i++) {
        arr4[i] = distrib2(gen);
    }

    ///вывод массивов
    std::cout << "1)" << std::endl;
    print(arr1);
    std::cout<< "2)" << std::endl;
    print(arr2);
    std::cout << "3)" << std::endl;
    print(arr3);
    std::cout << "4)" << std::endl;
    print(arr4);
    ///вывод суммы элементов кратных 5
    
    std::cout << "1)" << std::endl;
    printsum5(arr1);
    std::cout<< "2)" << std::endl;
    printsum5(arr2);
    std::cout << "3)" << std::endl;
    printsum5(arr3);
    std::cout << "4)" << std::endl;
    printsum5(arr4);


    return 0;
}