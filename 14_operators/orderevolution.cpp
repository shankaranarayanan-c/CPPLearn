#include <iostream>

int add(int x, int y){
    return x+y;
}

int main(){
    int x{3};
    std::cout<<add(x, ++x)<<"\n";                   //UB order of sequence cannot be determined. Avoid such ambigous statement
    return 0;
}