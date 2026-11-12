#include <iostream>
#include <string>

int main()
{
    int sum,extra;
    std::string f;

    do {
        sum = 0;
        extra = 0;

        std::getline(std::cin,f);
        switch (f[0])
        {
        case '+':


            for(double i;i<= f.length();i++){
                if (f[i]==char(' ') or f[i]==char('+')){
                    continue;
                }
                double x = f[i]-48;
                if (f[i+1] ==' '){
                    extra += x;
                    sum+=extra;
                }
                else{
                    extra *=10;
                    extra += x;
                    continue;
                }

            }
            std::cout<<sum;
            

        case 'e':
            break;

        }
   }while(f[0]!='e');
return 0;
}