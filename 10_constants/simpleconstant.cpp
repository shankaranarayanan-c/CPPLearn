#include <iostream>

//Three ways to define constants 
// 1. Obj like macros with substitution text
// 2. Const Variables
// 3. Enumerated constants


// #define PI 1.41                                      //has no scoping, available throught, not visible to the compiler or debugger

// enum color{
//     red, blue, green
// }

int main(){

    //const is called type qualifier which alters the behaviour. Volatile is another type qualifier
    const float pi{1.41f};                              // int const is possible but not preferred, const should be initialized during definition
    // pi = 4.5f;                                       // compilation error as constants cannot be modified
    std::cout<<"pi: "<<pi<<'\n';

    int x;
    x = 10;
    const int y{x};                                     // can be initialized with non const by the value has to be initialized
    x = 20;                                             // The value of y is not altered here Y is initialized with the value of X
    std::cout<<"y: "<<y<<'\n';  

    return 0;
}