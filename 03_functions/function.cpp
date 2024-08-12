#include<iostream>

int add(int x, int y){
    int sum = x + y;
}

int main(){                                  //function header

    // nested functions are not supported
    // void fun(){
    //     std::cout<<"hi nested!";
    // }

    int x;                                  //function body

    std::cout<<"sum is: "<<add(700,500)<<"\n";        //undefined behaviour

    return 0;                               //function return value optional for main and zero is returned by default
}