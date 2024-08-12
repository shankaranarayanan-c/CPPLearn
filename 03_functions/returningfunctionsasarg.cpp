#include <iostream>

int add(int x, int y){                          //parameter x and y are copy initialized with values from args
    return x+y;
}

void printValue(int val){                       //val is a local variable
    std::cout<<"The sum is "<<val<<std::endl;
}

// used for backward compatibilty
int getValue(int){                              //warning from unreferenced parameter can be removed by omitting name and it becomes unnamed parameter
    int inp;
    std::cout<<"Enter a number: "<<std::endl;
    std::cin>>inp;
    return inp;
}

int main(){

    printValue(add(getValue(1), getValue(2)));    //returning values of functions are used as args all these return values are stored in temp obj or anonymousobj
    
    return 0;

}