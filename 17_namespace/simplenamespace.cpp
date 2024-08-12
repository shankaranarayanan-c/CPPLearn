#include <iostream>

namespace Foo{                                  // Usually the names are entered in camelcase
    void printHello(){
        std::cout<<"Hello from Foo \n";
    }
};                                              // Optionally the namespace can be terminated with ;


namespace Goo{
    void printHello(){
        std::cout<<"Hello from Goo \n";
    }
}

int main(){

    Foo::printHello();
    Goo::printHello();
    
    return 0;

}