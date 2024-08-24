#include <iostream>

int main(){
    constexpr int x = 10;
    if constexpr(x == 10){                                  // compiler optimizes during compile time from C++17
        std::cout <<"X is expected \n";
    }else{
        std::cout <<"X is not as expected \n";   
    }
}
