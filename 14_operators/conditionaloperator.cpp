#include <iostream>

int main(){

    std::cout<<" "<<(true?3:4)<<'\n';
    std::cout<<" "<<(true?-1:8u)<<'\n';                      //  if operand doesnt match compiler tries to convert implicitly, signed is converted to unsigned 
    // std::cout<<" "<<false?9:"test"<<'\n';                 // both operands should have matching type, implicit conversion not possible so error
    return 0;
}