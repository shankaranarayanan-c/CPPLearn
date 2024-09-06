#include <iostream>

int main(){
    const int i{static_cast<int>(5.6)};                                   // potentially loss of data from one type to another type
    
    float j{1.23456789};                                                  // loss of precision is not narrowing

    constexpr uint k{i};                                                  // some constexpr conversion is not narrowing
    // constexpr uint l{-2};                                              // Narrowing

    std::cout<<" i: "<<i<<'\n';
    std::cout<<" j: "<<j<<'\n';
    std::cout<<" k: "<<k<<'\n';
    // std::cout<<" l: "<<l<<'\n';
    
    return 0;
}