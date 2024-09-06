#include <iostream>
#include <typeinfo>

int main(){
    int x{5};
    double y{4.5};

    std::cout<<" type id: "<<typeid(x+y).name()<<" : "<<x+y<<'\n';                      // int promoted to double
    

    std::cout<<" type id: "<<typeid(5u-10).name()<<" : "<<(5u-10)<<'\n';                // int promoted to uint

    return 0;
}