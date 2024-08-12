#include<iostream>

int main(){
    
    //std::cout is buffered only when the buffer is full the contents are flushed.
    // << insertion operator
    std::cout<<"Hi"<<std::endl; // std::endl not only introduces new line but also flushes the content to output stream immediately may downgrade performance
    std::cout<<"World"<<'\n';   //Single Line Feed LF is better and it is considered as single character ASCII value LF

    
    int x;
    int y;
    std::cout<<"Enter two numbers: \n";

    // >> extraction operator to get input is also buffered check with spaces / tabs as limiter
    std::cin>>x;
    std::cin>>y;

    std::cout<<"x: "<<x<<"y: "<<y<<std::endl;
    return 0;
}