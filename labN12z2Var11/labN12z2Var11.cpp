#include <iostream>
#include <vector>
#include <clocale>
#include <random>
#include <windows.h>

/// функция для вывода массивов 
void print(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void printsum5(const std::vector<int>& arr,std::vector<int>& arr2) {
    arr2.clear();
    int sum = 0;
    for (int x=0; x<arr.size();x++) {
        if (arr[x] % 5 == 0) {
            sum += arr[x];
            arr2.push_back(arr[x]);
        }
    }
    print(arr2);
    std::cout << sum << std::endl;
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");
    int k;
    
    std::vector<int> arr;
    std::cout << "Введите значение k (3,9): ";
    std::cin >> k;
    if (k <= 0) {
        std::cout << "k должно быть положительным" << std::endl;
        return 1;
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 11);
    std::uniform_int_distribution<int> distrib2(k / 2, k * 7 / 2);

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

    std::cout << "номера (индексы) и сумму элементов, значения которых лежат в диапазоне [min+(max-min)/2, max:" << "\n";

    
    std::cout << "1)" << std::endl;
    printsum5(arr1,arr);
    std::cout<< "2)" << std::endl;
    printsum5(arr2, arr);
    std::cout << "3)" << std::endl;
    printsum5(arr3, arr);
    std::cout << "4)" << std::endl;
    printsum5(arr4, arr);


    return 0;
}