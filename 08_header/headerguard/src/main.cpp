#include"add.h"                           

//compile using
//g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror src/main.cpp src/add.cpp inc/add.h -o addexe -I inc/


int main(){
    std::cout<<"Sum of 7 and 3 is: "<<add(7,3)<<" \n";
    foo();
    return 0;
}