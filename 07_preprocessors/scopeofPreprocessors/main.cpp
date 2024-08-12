#include"header.h"

int main(){

    #ifndef LINUX

    std::cout<<" Not in Linux! \n";

    #else
    std::cout<<"In Linux ! \n";
    #define ERROR                       //The value defined here is not scoped and visible only to the next statements
    foo();
    #endif

    return 0;
}