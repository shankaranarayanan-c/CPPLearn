#include <iostream>

//forward declaration to notify cmp that the def exists elsewhere
//used for var, types etc.,
//reordering of func will not help every time it also breaks circular dependencies

int add(int x, int y);

int main(){
    std::cout<<"Sum is: "<<add(3,2)<<std::endl;
    return 0;
}

int add(int x, int y){
    return x+y;
}