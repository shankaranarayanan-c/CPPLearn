#include <iostream>

void foo(){
    std::cout<<"Hi\n";
    return;                                 //Not necessary
}

int bar(){
    return 7;                               //only first return statement is considered
    return 8;
}

int main(){

    std::cout<<"bar(): "<<bar()<<"\n";
    // std::cout<<"foo(): "<<foo()<<"\n";   //compilation error due to non value returning functions
                                            //return in main() is optional by default 0 is returned
}