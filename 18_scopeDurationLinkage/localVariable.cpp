#include <iostream>

int main(){

    int lv1;                                // scope, lifetime, duration begins here for lv1
    {
        lv1 = 10;
        int lv2 =20;                        // scope, lifetime, duration begins here for lv2
        std::cout<<"value of lv2: "<< lv2;
    }                                       // scope, lifetime, duration ends here for lv2
    std::cout<<"value of lv1: "<< lv1;
    return 0;
}                                           // scope, lifetime, duration ends here for lv1