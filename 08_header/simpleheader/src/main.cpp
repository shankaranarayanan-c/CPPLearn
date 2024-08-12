#include"add.h"                 //dont provide relative path rather specify list of include dir to compiler
#include<iostream>              //start with pair header, other user defined headers, 3rd party header and finally STL headers

//compile using
//g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror src/main.cpp src/add.cpp inc/add.h -o addexe -I inc/

int main(){
    std::cout<<"Sum of 7 and 3 is: "<<add(7,3)<<" \n";
    return 0;
}