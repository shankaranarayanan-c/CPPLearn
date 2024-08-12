#include "mathConst.h"
#include <iostream>


// compile with -Wshadow
// g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -Wshadow source/main.cpp -o globalVarexe -I include/

int main(){
    double g_Glaisher{3.78};                                //variable shadowing
    std::cout<<"Exponention: "<< ::g_Exp<<"\n";
    std::cout<<"local Glaisher: "<< g_Glaisher<<"\n";
    std::cout<<"global Glaisher: "<< ::g_Glaisher<<"\n";
    std::cout<<"Pi: "<<Math::g_Pi <<"\n";
    return 0;
}