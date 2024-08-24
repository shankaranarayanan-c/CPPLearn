#include <iostream>

int main(){

    char a{65};
    char b = 'df';                          //narrowing conversion 

    std::cout<<"a: "<<a<<'\n';
    std::cout<<"b: "<<b<<'\n';              //UB behaviour

    return 0;
}