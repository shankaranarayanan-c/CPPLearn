#include<iostream>
#include<bitset>

int main(){
    std::bitset<8> a{0b00000000};
    a.set(2);
    a.reset(2);
    a.flip(2);

    std::cout<<"Value "<<a<<"\n";

    std::cout<<"Total bits: "<<a.size()<<"\n";
    std::cout<<"Total bits set:  "<<a.count()<<"\n";
    std::cout<<"Any bit are true: "<<a.any()<<"\n";
    std::cout<<"No bits are true: "<<a.none()<<"\n";

    return 0;
    }