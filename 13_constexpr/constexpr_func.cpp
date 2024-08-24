#include <iostream>

constexpr double PI{1.41};

void printHello(){
    std::cout<<"Radius cannot be negative! \n";
}

// implicitly inline and exempted from ODR as compiler needs full definition
// if constexpr are to be executed at compile time / runtime full definition is needed. If used more than one translation unit move the def to header file
// A constexpr func should satisfy below rules
// 1. all param are of literal type
// 2. return type should be literal type
// 3. There exist one control flow through with the function can be executed at compile time even though it has a call to non constexpr fun

constexpr double circleCirumference(double radius){                         // parameteres are not constexpr or constexpr parameters cant be used
    // radius > 0 ? printHi() : printHello();                               // call to be nonconstexpr can be made but there should exist one option to execute at
    radius > 0 ? void(0) : printHello();                                    // compile time
    return 2 * PI * radius;                                                
}

constexpr double printHi(){
   return circleCirumference(4.0);
}

// consteval int areaSquare(int side){                                      //only executed at compile time from C++20
//     return side*4;
// }

// constexpr double dynamicCircleCirumference(){
    // double radius{};
    // std::cout<<"Enter the radius: ";                                     //only call to constexpr function can be made
    // std::cin>>radius;
    // return 2 * PI * radius;
// }

int main(){

    constexpr double cirucumference{circleCirumference(2)};                 //only constexpr func can be used within constexpr to make it resolved at compile time
    std::cout<<"circumference: "<< cirucumference<<'\n';

    double radius{};
    std::cout<<"Enter the radius: ";
    std::cin>>radius;
    double dynamicCircumference{circleCirumference(radius)};                //constexpr func can also be used within non constexpr var, it will executed at runtime
    std::cout<<"Runtime circumference: "<< dynamicCircumference<<'\n';
    
    constexpr double newCircumference{printHi()};
    std::cout<<"new circumference: "<< newCircumference<<'\n';
    
    return 0;
}