#include <iostream>

namespace math{
    extern const double pi;                         // constexpr cant be forward declared and has to be used with const as runtime const
}                                                   // cant be used where the compile time constant is expected cant be optimized by the compiler as its runtime

int main(){
    std::cout<<"The value of PI: "<<math::pi<<'\n';
    return 0;
}