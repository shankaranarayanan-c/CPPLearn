#include <iostream>

int main(){
    double y{41234987.5};
    int x{static_cast<int>(y)};                     //explicit cast here where double is downcasted to int
    short z{static_cast<short>(x)};                 //UB if the cast value doesnt fit into the new type
    char a{'a'};

    std::cout<<"x: "<<x<<'\n';
    std::cout<<"z: "<<z<<'\n';
    std::cout<<"a: "<<static_cast<int>(a)<<'\n';

    return 0;
}