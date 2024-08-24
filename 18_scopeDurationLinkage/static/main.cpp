#include <iostream>

void foo(){
    int i{0};
    i++;
    std::cout<<"In foo for the "<<i<<" time \n";
}

void bar(){
    static int i{0};                                            // initialized only once
    i++;
    std::cout<<"In bar for the "<<i<<" time \n";
}

void moo(const int x){
    constexpr int a{5};
    static const int b{x};
    // a++;
    // b++;
    std::cout<<"In moo a: "<<a<<" b: "<<b<<'\n';
}

// extern static void display();                                // static functions are visible within the same translation unit

int main(){
    foo();
    foo();
    foo();

    bar();
    bar();
    bar();

    moo(1);
    moo(2);
    return 0;
}