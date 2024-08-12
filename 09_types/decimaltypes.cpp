#include <iostream>

int main(){
    float a{4.4345f};                                   //f suffix for float type
    double b{5.45365234925921};                         //std::set_precision() to set the value

    std::cout<<"float value: "<<a<<"\n";
    std::cout<<"double value: "<<b<<"\n";

    double c{0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1};  //some times we may get rounding error where the value may be 0.99
    std::cout<<"sum of 0.1 * 10: " <<c<<"\n";

    double x{1.0 / 0.0};
    double y{-23.0 / 0.0};
    double z{0.0 / 0.0};
    std::cout<<"positive divide by 0: "<<x<<"\n";       //INF
    std::cout<<"negative divide by 0: "<<y<<"\n";       //-INF
    std::cout<<"zero divide by 0: "<<z<<"\n";           //NaN
    
    return 0;
}