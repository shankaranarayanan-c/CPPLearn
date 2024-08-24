#include <iostream>

namespace math{
    constexpr double pi{3.141};
}

inline namespace math_v1{                                           // used for versioning the content without breaking
    constexpr double pi{3.1412};
}

int main(){
    std::cout<<"old version: "<< math::pi<<'\n';
    std::cout<<"new version: "<< math_v1::pi<<'\n';
    std::cout<<"default version: "<<pi<<'\n';
    return 0;
}