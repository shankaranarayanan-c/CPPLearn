#include<iostream>

int main(){
    std::cout<<"Often compiler optimizes the code by changing to enhance capability \n";
    std::cout<<"These changes are non complaint with the C++ standards and are enabled default by the compilers \n";
    std::cout<<"To switch of these extension in g++ use the flag -pedantic-errors \n";
    std::cout<<"g++ -std=c++11 -pedantic-errors your_file.cpp -o your_program \n";
    std::cout<<"Turn on the maximum warnings and errors and also treat warnings as errors \n";
    std::cout<<"-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror \n";
    std::cout<<"The flags can be added in command line for gcc / cmake or in the tasks.json file within VS code just above the ${file} within args \n";
    std::cout<<"In the end it looks like \n";
    std::cout<<"g++ -std=c++11 -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror compilerextensions.cpp -o compilerextexe \n";
    std::cout<<"use -std=c++11 / 14 / 17 to enforce a standard \n";
    return 0;
}