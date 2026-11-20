#include <iostream>
#include <vector>


void primesieve(int n,std::vector<int>& arr){
    for (int i=2; i<=n; i++){
        arr.push_back(i);
    }
    for (int j = 0; j < (int)arr.size(); j++){   
        int f = arr[j];
        if (f == -1) continue;   
        if (f * f > n) break;    
        for (int i = 0; i < (int)arr.size(); i++){   
            if (arr[i] != f && arr[i] % f == 0){
                arr[i] = -1;
            }
        }
    }   
}

void print(std::vector<int>& arr){
    for (int i : arr){
        if (i!=-1){
            std::cout<<i<<" ";
        }
    }
}
void printcount(std::vector<int>& arr){
    int count =0;
    for (int i : arr){
        if (i!=-1){
            count+=1;
        }
    }
    std::cout<<count;
}

int main(){
    int n; 
    std::cin>>n;
    std::vector<int> arr;
    primesieve(n,arr);
    printcount(arr);
    return 0;
}