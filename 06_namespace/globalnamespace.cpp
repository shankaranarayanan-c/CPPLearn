#include<iostream>

void hi(){
    std::cout<<"hi"<<"\n";
}

int main(){
    ::hi();                 //absolute qualified name :: is the scope resolution operator. LHS is the name space name and RHS is the idenfier
}