#include <iostream>

void clean(){
    std::cout<<"free up resources! \n";
}

int main(){
    std::atexit(clean);

    int i;
    std::cout<<"Enter the halt option 1- Exit 2 - Abort 3 - Terminate";
    std::cin>>i;

    switch (i)
    {
    case 1:
        std::exit(i);
        break;
    case 2:
        std::abort();
    case 3:
        std::terminate();
    default:
        break;
    }

    return 0;
}