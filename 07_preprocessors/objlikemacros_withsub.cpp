#include <iostream>

#define MY_NAME "SHANKAR"                   // discouraged access instead global inline variables [global constants]

int main(){
    std::cout<<"I am "<<MY_NAME<<"\n";      // during preprocessing MY_NAME is replaced with the literal value
    return 0;
}