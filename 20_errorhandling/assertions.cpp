#include <iostream>
#include <cassert>

void divide(int a, int b){
    assert(b != 0 && "divisor cant be zero");                   // runtime assertions can be turned off in production builds with flag NDEBUG
    // g++ -DNDEBUG assertions.cpp 
    // const int x{3};
    // static_assert(x > 5, "valid condition");                 // compile time assertion with failing of compilation if condition is not satisfied
    std::cout<<"div value: "<<a/b;
}

int main(){
    divide(10,1);
    return 0;
}