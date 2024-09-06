#include <iostream>

int main(){

    std::cout<<"Hello World! \n";                               //C Style strings not flexible, cannot store large size strings to shorted memory UB
    
    std::string str1{};
    std::cout<<"str1: "<<str1<<" in address : "<<&str1<<'\n';
    str1="Shankar";                                             //memory allocated dynamically and hence it is costly operation
    std::cout<<"str1: "<<str1<<" in address : "<<&str1<<'\n';
    
    //getting a string input
    std::string inputStr{};
    std::cout<<"Enter a string: ";
    std::cin>>inputStr;
    std::cout<<"Entered string: "<<inputStr<<'\n';

    //use std::getline
    std::cout<<"Enter a string with space: ";
    std::getline(std::cin,inputStr);
    std::cout<<"Entered string: "<<inputStr<<'\n';

    //escape leading spaces and delimit with new line using std::ws
    std::cout<<"Enter a string with space: ";
    std::getline(std::cin>>std::ws,inputStr);
    std::cout<<"Entered string: "<<inputStr<<'\n';

    std::cout<<"Lenght of string: "<<inputStr.length()<<'\n';


    // constexpr std::string str2{"hi"};                        //std::string requires dynamic storage and hence the constexpr is not supported

    // Dont pass string by value, return by value is ok.                   

    return 0;
}