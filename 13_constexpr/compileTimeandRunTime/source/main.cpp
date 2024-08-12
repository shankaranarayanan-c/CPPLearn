#include "shapeCalc.h"
#include <iostream>

//complle with
// g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -O2 source/main.cpp source/shapeCalc.cpp include/shapeCalc.h -o shapecalcexe -I include/
// -O2 option instructs compiler to turn on optimization where the compile time constexpr are executed. During debug builds these optimization are turned off.

int main(){
    constexpr double circle{circleCircumference(5.6)};
    std::cout<<"The circle circumference: "<<circle<<'\n';

    double side{};
    std::cout<<"Enter the side of the square: ";
    std::cin>>side;
    double square{squareArea(side)};  
    std::cout<<"The area of square: "<<square<<'\n';

    return 0;
}