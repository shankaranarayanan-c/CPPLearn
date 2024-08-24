// #include "constant.h"
#include <iostream>

extern int x;
int z{x};                                                       // Value of Z is ambigious

void foo(){
    x++;
}

void bar(){
    x=x*3;
}


int moo();

extern int getMutex();
extern void setMutex(int);

int main(){
    foo();
    x=7;
    bar();
    std::cout << "value of X is unpredictable: " << x<<'\n';
    std::cout << "value of Z is unpredictable: " << z<<'\n';
    std::cout << "value of Y from moo: " << moo()<<'\n';

    // Best practices
    setMutex(1);
    std::cout << "Mutex value: "<< getMutex() << '\n';
    return 0;
}