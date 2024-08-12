#include <iostream>
#include <string>
#include <string_view>

int main(){

    std::cout<<"long: "<<34L<<'\n';                     
    std::cout<<"unsigned: "<<34L<<'\n';
    std::cout<<"long long: "<<1234567891234567891LL<<'\n';                       //ll or LL suffix only preferebly LL
    std::cout<<"unsigned long: "<<2341UL<<'\n';                                  //Ul, ul, UL, uL
    std::cout<<"unsigned long long: "<<12345678912345678912ULL<<'\n';            //ull, uLL, Ull, ULl, UlL, ULL
    std::cout<<"float: "<<5.6f<<'\n';                                            //mandatory

    using namespace std::string_literals;
    std::string s{"hello"s};
    std::cout<<"string: "<<s<<'\n';

    using namespace std::string_view_literals;
    std::string_view sv{"hi"sv};
    std::cout<<"string: "<<sv<<'\n';

    return 0;
}