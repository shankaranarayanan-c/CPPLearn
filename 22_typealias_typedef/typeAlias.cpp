#include <iostream>

int main(){
    using speed = double;                                   // platform independent coding, easier code maintanence but difficult to interpret
    int distance{100};
    int time{60};

    speed s = static_cast<double> (distance) / time;
    std::cout<<"speed : "<<s<<'\n';

    return 0;
}