#include <iostream>

int main(){

    int var{4};                         //nonconst
    const int compiletimeConst{7};      //compile time constant
    const int runtimeConst{var};        //runtime const value can be set at the runtime

    constexpr int x{};                  //always compile time const value should be initialized at compile time
    // constexpr int y{var};            //runtime constant exp are not supported within constexpr
    // constexpr int y{runtimeConst};   //runtime constant exp are not supported within constexpr
    constexpr int y{compiletimeConst};  //runtime constant exp are not supported within constexpr
    constexpr double z{9.234};          //constexpr supports compile time constants other than integral types

    std::cout<<"var: "<<var<<'\n';
    std::cout<<"compiletimeConst: "<<compiletimeConst<<"\n";
    std::cout<<"runtimeConst: "<<runtimeConst<<"\n";
    std::cout<<"x: "<<x<<'\n';
    std::cout<<"y: "<<y<<'\n';
    std::cout<<"z: "<<z<<'\n';

    return 0;
}