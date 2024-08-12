#include <iostream>

int add(int, int);

int main(){
    std::cout<<"Sum is: "<<add(3,4)<<std::endl;
}

//compile using
//g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror add.cpp main.cpp -o sumexe
//order doesnt matter as compiler doesnt remember content of each file