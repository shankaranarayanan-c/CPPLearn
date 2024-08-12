#include <iostream>

extern const double g_pi;
// extern constexpr double g_exp;                               // constexpr variables cannot be forward declared
extern const double g_exp;                                      // The constexpr variable can be forward declared as const by compiler will treat as runtime const
extern int g_a;

int main(){
    std::cout<<" value of pi: "<<g_pi<<"\n";
    std::cout<<" value of exp: "<<g_exp<<"\n";
    std::cout<<" value of a: "<<g_a<<"\n";

    return 0;
}