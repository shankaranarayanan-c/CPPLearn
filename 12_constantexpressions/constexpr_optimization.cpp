#include<iostream>

// optimization
// 1. reduces runtime as the expression are computed at complie time
// 2. reduces memory as the the x here in the give program may not be initialized


int main(){

    int x{3+4};                 // 3+4 is const expr but x is not a compile time const as const is not defined
    std::cout<<"x: "<<x<<'\n';  //compiler are free to optimize until the behaviour is not changed or identified. x can be replaced with "7"

    const int a{9};             //compiletime constant
    const int b{a};             //compiletime constant
    const int c{x};             //runtime constant as x is not a const exp it contains runtime expr

    const double d{4.4};        //4.4 is const expr but d is not an integral type and a runtime const

    std::cout<<"a: "<<a<<'\n';
    std::cout<<"b: "<<b<<'\n';
    std::cout<<"c: "<<c<<'\n';
    std::cout<<"d: "<<d<<'\n';

    return 0;
}