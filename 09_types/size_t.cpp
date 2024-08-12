#include <iostream>
#include <cstddef>

int main(){
    std::size_t intSize = sizeof(int);
    std::cout<<"size of int: "<<intSize<<"\n";
    std::cout<<"size if size_t: "<<sizeof(size_t)<<"\n";                    //Most likely the size of the largest type
    return 0;
}