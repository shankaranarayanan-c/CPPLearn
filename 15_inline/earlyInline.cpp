#include <iostream>

inline int add(int x, int y){                   // ask compiler to replace the function call with the def to optimize the performance.
    return x+y;                                 // however compiler may skip this optimization and not required to specify the inline here any more
}

int main(){

    std::cout<<"sum of 3+2: "<<add(3,2)<<'\n';
    return 0;

}