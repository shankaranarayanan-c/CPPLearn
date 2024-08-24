#include <iostream>

int main(){

    std::cout<<"Modulo : "<< 7 % 3 <<"\n";          // 1
    std::cout<<"Modulo : "<< 3 % 7 <<"\n";          // 3
    std::cout<<"Modulo : "<< 10 % -2 <<"\n";        // 0
    std::cout<<"Modulo : "<< -5 % 3 << "\n";        // -2
    std::cout<<"Modulo : "<< 4 % 0 << "\n";         // NaN / Core dumped   
    return 0;
}
