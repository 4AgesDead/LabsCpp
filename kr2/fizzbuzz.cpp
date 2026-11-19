#include <iostream>

void fizzbuzz(int n){

    for (int i =2; i<=n;i++){
        if (i%15==0){
            std::cout<<"Fizzbuzz";

        }
        else if (i%5==0 and i%3 !=0){
            std::cout<<"Buzz";
        }
        else if (i%3==0 and i%5 !=0){
            std::cout<<"Fizz";

        }
        else{
            std::cout<<i;

        }
        if (i<n){
            std::cout<<", ";

        }
        else{
            std::cout<<".";
        }
    }
}
int main(){
        int n; 
    std::cin>>n;
    fizzbuzz(n);
    return 0;
}