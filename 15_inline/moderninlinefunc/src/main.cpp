#include "mathvalue.hpp"
#include <iostream>

int getCMForaMetre();

inline int convertMetreToCM(int metre){
    std::cout<<"main \n";
    return metre * 1000;
}

int main(){

    std::cout<<"1 Metre is equal to : "<<getCMForaMetre()<<" CM\n";
    std::cout<<"10 Metre is equal to : "<<convertMetreToCM(100)<<" CM\n";


    return 0;
}