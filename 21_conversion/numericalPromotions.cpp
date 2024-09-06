#include <iostream>

void promoteToInt(int x){
    std::cout<<"Promoted int value: "<<x<<'\n';
}

void promoteToDouble(double y){
    std::cout<<"Promoted double value: " <<y<<'\n';
}

int main(){                                                             // no loss of data
    short a{2};                                                         // char to int and int to long are conversions and not promotions
    float c{4.5f};
    int e{5};
    char ch{'a'};

    promoteToInt(a);
    promoteToInt(false);
    promoteToInt(ch);


    promoteToDouble(c);
    promoteToDouble(e);

    return 0;
}