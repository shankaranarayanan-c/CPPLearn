#include <iostream>

int main()
{
    std::cout<<"Language standard: " <<__cplusplus <<"\n";
    switch (__cplusplus)
    {
    case 201103L:
        std::cout<<"c++11 \n";
        break;
    case 201302L:
        std::cout<<"c++13 \n";
        break;
    case 201703L:
        std::cout<<"c++17 \n";
        break;
    case 202002L:
        std::cout<<"c++20 \n";
        break;
    case 202302L:
        std::cout<<"c++23 \n";
        break;
    default:
        std::cout<<"pre c++11 or post c++23 \n";
        break;
    }
    return 0;
}