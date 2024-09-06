#include <iostream>

int main(){
    int x{5}, y{3};
    char c{'a'};

    double z = (double)x / y;
    std::cout<<"z: "<<z<<'\n';


    int *p = (int *)&c;                                                 // error behaviour no compile time type checking and not very easy to find

    return 0;
}