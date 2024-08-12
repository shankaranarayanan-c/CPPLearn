#include<iostream>

int main(){
    //less efficient
    int a;                                  // default initialization or variable definition
    int b = 10;                             // copy assignment intialization

    //hard to differentiate between function forward declaration
    int c(7);                               // direct intialization 
    
    //from c++11
    //preferred way of initialization
    int x{2};                               // direct list initialization or direct brace initialization
    int y={4};                              // direct list copy initialization
    
    //In most cases value initialization leads to 0 intialization
    int z{};                                //value initialization use when you will replace the value with another value soon

    //list intialization disallows narrowing conversion
    // int m{4.5}; // compiler error
    int n = 4.5;                            // no error and narrowly 4.5 is converted to 4
    int o{0};                               //use when you wnat to intialize to zero and make use of the value for computation

    [[maybe_unused]]double pi { 3.14159 }; //to overcome the warning if the variable is not used by compiler applicable from c++17

    std::cout<<"a: "<<a<<std::endl;         // undefined behaviour and doesnt compile when compiler flags are set
    std::cout<<"b: "<<b<<std::endl;
    std::cout<<"c: "<<c<<std::endl;
    std::cout<<"x: "<<x<<std::endl;
    std::cout<<"y: "<<y<<std::endl;
    std::cout<<"z: "<<z<<std::endl;
    std::cout<<"n: "<<n<<std::endl;
    std::cout<<"o: "<<o<<std::endl;
    return 0;
}