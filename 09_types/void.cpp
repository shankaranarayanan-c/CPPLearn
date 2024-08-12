#include <iostream>

void oldFunc(void){                                                     //explicit void
    std::cout<<"Backward compatible \n";
}

void newFunc(){                                                         //implicit void
    std::cout<<"Preferred C++ way \n";
}


int main(){
    // void x;                                                          //void not a concretetype its an incomplete type

    // oldFunc(void);                                                   //void is not a concrete type 
    oldFunc();
    newFunc();
    return 0;
}

