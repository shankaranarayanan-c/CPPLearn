#include<iostream>
#include<bitset>

int main(){
    //storage
    int decimal{100};
    int octal{015};
    int hexa{0xF};

    std::cout<<"decimal: "<< decimal<<'\n';
    std::cout<<"octal: "<<octal<<'\n';
    std::cout<<"hexa: "<<hexa<<"\n";
     
    //To print the numeral system values
    
    std::cout<<std::oct<<"octal: "<<octal<<'\n';
    std::cout<<std::oct<<"decimal: "<<decimal<<'\n';

    
    std::cout<<std::hex<<"hex: "<<hexa<<'\n';
    std::cout<<std::hex<<"decimal: "<<decimal<<'\n';

    std::bitset<8> bin{0b11011001};
    std::cout<<"bin: "<<bin<<'\n';

    return 0;
}