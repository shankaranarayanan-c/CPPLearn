#include<iostream>

#define LINUX

int main(){

    #ifdef LINUX                            //LINUX is not replaced by empty space as it is preprocessor statment

    std::cout<<"In LINUX block! \n";

    #endif
    
    #ifndef LINUX

    std::cout<<"NON LINUX BLOCK!" << LINUX; //This will be a compilation error

    This section will not compile

    #endif


    #if 0

    Even this section will not compile

    #endif


    return 0;
}