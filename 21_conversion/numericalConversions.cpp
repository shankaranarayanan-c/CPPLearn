#include <iostream>

void convertToInt(short x){
    std::cout<<"Converted int value: "<<x<<'\n';
}

void convertToFloat(float y){
    std::cout<<"Converted double value: " <<y<<'\n';
}

int main(){                                                             // There may be loss of data or signedness
    int i =32768;                                                       // int to long, short to char, int to unsigned, float to long double
    double j={5.4736};

    //value preserving
    convertToInt(i);
    convertToFloat(j);

    //reinterpretative
    long m{3452368456};
    int n = m;
    std::cout<<"value of n: "<<n<<'\n';
    
    int x = -7;
    uint y = x;
    std::cout<<"value of y: "<<y<<'\n';

    return 0;
}