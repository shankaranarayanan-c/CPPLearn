#include<iostream>

//x is out of scope
void fun(){
    std::cout<<"Hello"<<std::endl;
}


//scope is compile time property and lifetime is runtime property. If we access a variable after its lifetime it will produce UB
int main(){

    //x is coming in scope and alive
    int x; 

    //new scope begins here
    {
        //the value of x is assigned within this scope
        x = 10;
    }

    // the value of x assigned is not visible here and it may be UB
    std::cout<<"x: "<<x;

    return 0;
}
//x is going out of scope and destroyed