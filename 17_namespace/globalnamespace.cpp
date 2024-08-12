#include <iostream>

void printHello(){
    std::cout<<"Hello from globalnamespace! \n";
}

namespace Foo{
    void printHello(){
        std::cout<<"Hello from Foo namespace! \n";
    }

    void printHi(){
        std::cout<<"Hi \n";
        printHello();
        ::printHello();
    }
}

int main(){
    printHello();
    Foo::printHi();
    return 0;
}