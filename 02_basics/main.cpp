#include<iostream> // STL library header which provides standard input and output function

int main(){ // main entry point of execution
    //causes segfault - accessing invalid / unintialized memory or memory of another process
    // main(); // will cause error with compilation flag -pedantic-errors as accessing address of main is not allowed. 
     return 0;
}