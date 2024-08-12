#include <iostream>

int main(){
    int a{5};
    int b{6};

    if(a < 2 && ++b > 7){                               // value b is not incremented as the condition evaluation is short circuted
        std::cout<<"not executed! \n";
    }

    std::cout << "value of b: "<<b<<"\n";

    bool x{false};

    std::cout<<"value of x: "<< !!!x<<"\n";

    std::cout<<"value of ++++5 "<< ++++a<<"\n";
    return 0;
}