#include <iostream>
#include <string>
#include <string_view>

void printString(std::string givenString){                                                  //std string is initialized with copy as it is pass by value
    std::cout<<"Given String: "<<givenString<<'\n';
}

void printStringView(std::string_view givenString){                                         //no copy is made even string view is modfied it will not cause side effect 
    std::cout<<"Given Stringview: "<<givenString<<'\n';
}

std::string_view returnSV(){
    std::string a{"fun string"};
    return a;
}

std::string_view returnValidSV(){
    return "fun string";
}


int main(){

    std::string str1{"Hello"};                                                              //C style string is initialized with copy
    std::cout<<"C style string are treated as Objects address is: "<<&"Hello"<<'\n';
    // std::cout<<"C literals are treated as non Objects address is: "<<&5<<'\n';           //5 is not an lvalue
    //2 copies of "Hello is made" one for str1 and another for givenString if called

    std::string_view sv1{"Hi"};                                                             //no copy is made and string view is readonly cannot be intialized dynamically
    printStringView(sv1);                       
    printStringView(str1);                                                                  //Accepts std:;string
    printStringView("Test");                                                                //Also accepts c style strings
    // std::getline(std::cin>>std::ws, sv1);                                                //A string view value cannot be modified


    // printString(sv1);                                                                    //not supported
    printString(static_cast<std::string>(sv1));                                             //explicity cast to std::string

    constexpr std::string_view sv2{"Hello World"};
    std::cout<<"constexpr string view: "<<sv2<<'\n';


    std::string strOverWrite{str1};
    std::string_view stvOverWrite{str1};

    str1 = "Overwritten";
    std::cout<<"str1: "<<str1<<'\n';
    std::cout<<"strOverWrite: "<<strOverWrite<<'\n';                                         //refers to the old value since it has its own copy and not reference
    std::cout<<"stvOverWrite: "<<stvOverWrite<<'\n';                                         //it has references so new value of the old string size or UB
    stvOverWrite = "New Hi!";                                                                //Only reference is allowed to be updated and not value
    std::cout<<"stvOverWrite: "<<stvOverWrite<<'\n';


    {
        stvOverWrite = str1;
    }
    std::cout<<"stvOverWrite: "<<stvOverWrite<<'\n';                                        //Expected behaviour as the str1 is cstyle constant availble throught

    {
        stvOverWrite = std::string{"local update"};
    }
    std::cout<<"stvOverWrite: "<<stvOverWrite<<'\n';                                        //UB as the std::string is locally available

    stvOverWrite = returnSV();
    std::cout<<"stvOverWrite: "<<stvOverWrite<<'\n';                                        //UB as the std::string which is locally defined in fun may be deleted

    stvOverWrite = returnValidSV();
    std::cout<<"stvOverWrite: "<<stvOverWrite<<'\n';                                        //EB as the C style string is available across full program

    sv1 = str1;
    sv1.remove_prefix(1);                                                                   //start and end index are updated
    sv1.remove_suffix(1);
    std::cout<<"sv1: "<<sv1<<'\n';  
    std::cout<<"str1: "<<str1<<'\n';  
    return 0;
}