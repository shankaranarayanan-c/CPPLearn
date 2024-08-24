#include<iostream>

namespace{                                                      // unnamed namespace are visible only within the file / contents are internal linkage
    void foo(){
        std::cout<<"In anonmyous namespace! \n";
    }
}

int main(){
    foo();
    return 0;
}