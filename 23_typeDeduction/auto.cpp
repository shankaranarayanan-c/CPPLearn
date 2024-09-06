#include <iostream>

auto division(int x, int y){ 
    if(x > y)                            
        return x/y;
    // return 10.5;                                     // all the return statements within function should match for same type
    return 0;
}

auto mul(int x, int y);
auto add(int x, int y) -> int;

auto sub(auto x, auto y){                               // auto parameters are supported from c++20 compile with -std=c++20
    return x-y;
}

int main(){
    auto a{5};                                          // auto keyword deduces types from the given values
    auto b{'k'};
    auto c{67.87};
    constexpr int d{5};
    auto e{d};                                          // constexpr and other qualifiers will be auto removed
    static int f{10};
    auto g{f};

    // auto x{};                                        // cant deduce type if the values are not provided
    // auto f;

    // std::cout<<"mul: "<<mul(6,9)<<'\n';              // cannot fwd declare a function with auto type deduction return type can be specified using trail syntax
    std::cout<<"add: "<<add(6,9)<<'\n';
    std::cout<<"sub: "<<sub(6,9)<<'\n';
}

auto mul(int x, int y){
    return x*y;
}

auto add(int x, int y) -> int{
    return x+y;
}