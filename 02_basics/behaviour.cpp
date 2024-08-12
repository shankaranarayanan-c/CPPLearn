#include <iostream>

int main(){

    int x;

    std::cout<<"x: "<<x<<'\n';                  // undefined behaviour or UB
    std::cout<<"int size: "<<sizeof(int)<<"\n"; // implementation defined behaviour that can vary across OS or compilers
    
    //unspecified behaviour

    return 0;
}