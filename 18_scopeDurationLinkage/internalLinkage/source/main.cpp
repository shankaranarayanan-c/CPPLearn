#include <iostream>

// extern double pi;                                                            //staic global variables are has internal linkage not available outside TU
static double pi{2.141};
// extern int twice;                                                            //const and constexpr global variables has internal linkage and static keyword is not needed
const int twice{4};
constexpr int thrice{6};
int a;                                                                          //External / Internal non const variables are initialized by default
static int b;

extern std::string gMessage;
// static std::string gMessage{};                                               //shadowing of the global variable gMessage
// std::string gMessage{};                                                      //linker error gMessage definition violates ODR.
extern double areaOfCircle(double radius);

int main(){

    std::cout<<"Internal linked variable pi: "<<pi<<"\n";
    std::cout<<"Internal linked variable twice: "<<twice<<"\n";
    std::cout<<"Internal linked variable thrice: "<<thrice<<"\n";

    std::cout<<"External linked variable message: "<<gMessage<<"\n";
    std::cout<<"External linked function area of circle: "<<areaOfCircle(3.4)<<"\n";
    std::cout<<"External linked variable a: "<<a<<"\n";
    std::cout<<"Internal linked variable b: "<<b<<"\n";

    return 0;
}