#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string str;
    char mas[] = {'#', '!', '@'};
    int n;

    std::cout<<"Введите n"<<std::endl;  
    std::cin>>n;

    std::vector<std::string> arr;
    
    std::cout<<"Введите строки"<<std::endl;
    for (int i =0; i<n; i++){
        std::getline(std::cin, str);
        arr.push_back(str);
    }

    std::cout<<"Строки с не более 5 символов из набор # @ !"<<std::endl;

    int count;
    for (std::string i : arr){count=0;
        for (char j : i){
	   if (j == mas[0] or j == mas[1] or j == mas[2])count++;
	}if (count<=5) std::cout<<i<<std::endl;
    }

    return 0;
}
