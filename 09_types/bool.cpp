#include <iostream>

int main(){
    
    bool x{true};
    std::cout<<"x: "<<x<<"\n";
    std::cout<<std::boolalpha;
    std::cout<<"x: "<<x<<"\n";

    bool y{0};
    bool z = -7;
    std::cout<<"y: "<<y<<"\n";
    std::cout<<"z: "<<z<<"\n";
    return 0;
}