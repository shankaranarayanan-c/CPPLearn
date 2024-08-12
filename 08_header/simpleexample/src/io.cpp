#include"io.h"

int readNumber(){
    int x;
    std::cout<<"Enter a number: ";
    std::cin>>x;
    return x;
}

void writeAnswer(int value){
    std::cout<<"The value is: "<<value<<"\n";
}