#include <iostream>

char getInput(){
    char a{};
    std::cin>>a;
    return a;
}

void displayIfVowel(char c){
    switch (c)
    {
    case 'a':                                                       // only const values of integers are allowed to be in case no relational operators
    case 'A':                                                       // the values should not be identical
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    // case 'o':
    case 'O':
    case 'u':
    case 'U':
        std::cout<<"The entered character is a vowel! \n";
        break;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
        std::cout<<"The give char is a number! \n";
        // int j = 0;                                                           // no initialization allowed
        int j;                                                                  // only definition allowed
        [[fallthrough]];                                                        // To inform the fallthrough is intentional from C++17 should have null statement
    default:
        j=5;                                                                    // all statements are in the same scope
        std::cout<<"Exit from Switch \n";
    }
}

void calc(){
    std::cout<<"Enter the mathematical operator: ";
    char op{getInput()};
    std::cout<<"Enter the first number: ";
    char x;
    x = getInput();
    std::cout<<"Enter the second number: ";
    char y;
    y = getInput();
    switch (op)
    {
    case '+':
        std::cout<<" Sum is : " <<(x-'0')+(y-'0')<<'\n';
        break;
    case '-':
        std::cout<<" Sum is : " <<(x-'0')-(y-'0')<<'\n';
        break;
    case '*':
        std::cout<<" Sum is : " <<(x-'0')*(y-'0')<<'\n';
        break;
    case '/':
        std::cout<<" Sum is : " <<(x-'0')/(y-'0')<<'\n';
        break;
    default:
        std::cout<<"Unsupported operation\n";
        break;
    }
}

int main(){
    char c{getInput()};
    displayIfVowel(c);
    calc();
    return 0;
}