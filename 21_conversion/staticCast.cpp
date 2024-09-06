#include <iostream>

int main(){
    int x{4},y{3};
    double z = static_cast<double>(x) / y;

    std::cout<<"z: "<<z<<'\n';

    char ch{'a'};
    int *ptr;
    // ptr = static_cast<int *>(&ch);                                   // compile type checking and easy to locate
    return 0;
}