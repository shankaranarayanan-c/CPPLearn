#include <iostream>

int main(){
    int a{(10,4)};         // , operator executes the rhs at the last so 4 is executed and returned here (10 , 4) is evaluated
    // int b = 6,9;            // here b = 6 is assigned and then 9 is discarded

    std::cout << "value of a: "<< a<<"\n";
    // std::cout << "value of b: "<< b;    
    return 0;
}