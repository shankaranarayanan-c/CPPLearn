#include <iostream>

#define LINUX

void foo(){

    #ifdef ERROR
    std::cout<<"Error Occured! \n";
    #else
    std::cout<<"No Error! \n";
    #endif

}