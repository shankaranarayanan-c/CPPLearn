#include <iostream>

int main(){
    short x{32767};                     //by default it is signed. size of short is 2 bytes. 1 bit for sign represenation. 2 pow 15 32768.

    // binary represenation of 32768 = 1000 0000 0000 0000 [2s compliment of -32768]
    // Most significant bit is sign bit and it is considers as negative
    //

    std::cout<<"Before x: "<<x<<"\n";   

    x=x+2;                              //This will cause overflow resulting in UB

    std::cout<<"After  x: "<<x<<"\n";

    return 0;
}