#include <iostream>

int main(){
    double x{4};                    //the int value 4 is implicitly promoted to double
    int y{'c'};                     //the char value c is implicitly promoted to int
    
    // Narrow conversion as there might be loss of data so compiler throws warnings
    // std::uint16_t z{67};
    // std::int16_t a{z};
    // int b = x;

    std::cout<<"x: "<<x<<'\n';
    std::cout<<"y: "<<y<<'\n';

    return 0;
}