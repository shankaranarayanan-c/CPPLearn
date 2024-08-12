#include <iostream>

int main(){
    double a{100.00 - 99.99};
    double b{10.00 - 9.99};

    if(a == b){                                     // Not equal because of floating point rounding errors
        std::cout<<"value is equal! \n";
    }else{
        std::cout<<"value is not equal \n";
    }


    if((a-b) <= 0.01 ? true : false){
        std::cout<<"a and b are close enough \n";
    }
    return 0;
}