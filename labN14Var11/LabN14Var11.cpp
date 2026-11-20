#include <iostream>
#include <vector>
#include <random>
#include <clocale>

std::vector<std::vector<double>> matrixmade(int m, int n ,double k){
   std::vector<std::vector<double>> arr;
   std::vector<double> arradd;

   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_real_distribution<double> distrib(-k,2*k);

   for (int i = 0; i < m; i++){
      arradd.clear();
      for (int j = 0; j < n; j++){arradd.push_back(distrib(gen));}
      arr.push_back(arradd);
   }
  
   return arr;
}

void print(const std::vector<std::vector<double>>& arr){
   for (const std::vector<double>& i : arr){
         for(double j : i){
             std::cout<<j<<" ";
         }std::cout<<std::endl;
  
      }
}

double positivesum(const std::vector<std::vector<double>>& arr){
   double sum = 0;
   bool checker;
   for (const std::vector<double>& i : arr){
      checker = true;
         for(double j : i){
            if (checker){checker=false;continue;};
            if (j>0)continue;
            sum+=j;
            checker = true;
         }
  
      }
   return sum;
} 

int main(){
   std::setlocale(LC_ALL, ".UTF-8");

   int m, n;
   double k, sumA, sumB, sumC;
   
   std::cout<<"Введите m"<<std::endl;
   std::cin>>m;
   std::cout<<"Введите n"<<std::endl;
   std::cin>>n;
   std::cout<<"Введите k"<<std::endl;
   std::cin>>k;   

   std::vector<std::vector<double>> A = matrixmade(m,n,k);
   std::vector<std::vector<double>> B = matrixmade(m,n,k);
   std::vector<std::vector<double>> C = matrixmade(m,n,k);
   
   std::cout<<"Ваши три матрицы:"<<std::endl;
   std::cout<<"A="<<std::endl;
   print(A);
   std::cout<<"B="<<std::endl;
   print(B);
   std::cout<<"C="<<std::endl;
   print(C);

   sumA = positivesum(A);
   sumB = positivesum(B);
   sumC = positivesum(C);

   std::cout<<"Наименьшая сумма положительных элементов четных столбцов:"<<std::endl;
   if(sumA<sumB){if (sumA<sumC){std::cout<<"A";}else{goto Cwin;}}
   else{if(sumB<sumC){std::cout<<"B";}else{Cwin:std::cout<<"C";}}

   return 0;
}
