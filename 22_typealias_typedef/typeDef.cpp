#include <iostream>

int main(){
    typedef double speed;                                           // prefer type alias over typedef as its not a type def but rather an alias
    int distance{100};
    int time{60};

    speed s = static_cast<double>(distance) / time;
    std::cout<<"speed: "<<s<<'\n';

    return 0;
}