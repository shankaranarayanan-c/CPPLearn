#include <iostream>

namespace Foo{
    namespace Goo{
        void printHello(){
            std::cout<<"Hello from Foo Goo! \n";
        }
    };
};

namespace Foo::Bar{
    void printHello(){
        std::cout<<"Hello form Foo Bar! \n";
    }
}

int main(){
    namespace ns1 = Foo::Goo;
    namespace ns2 = Foo::Bar;

    ns1::printHello();
    ns2::printHello();

    return 0;
}