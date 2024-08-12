#include <iostream>

void hi(){
    std::cout<<"hi in main";
}

int main(){
    hi();
}

//compile using
//g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror file1.cpp main.cpp -o greetexe
//order doesnt matter as compiler doesnt remember content of each file