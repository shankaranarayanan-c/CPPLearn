#include <iostream>
#include <random>

void displayRandomNos(){
    std::random_device rd{};
    std::mt19937 mersenneTwister{rd()};                                     //inital seeding from random_device
    for(int i = 1 ; i<=10 ; i++){
        std::cout<<mersenneTwister()<<" ";
        if(i % 5 == 0){
            std::cout<<'\n';
        }
    }
}

void rollDie(){
    std::mt19937 mersenneTwister{std::random_device{}()};                   //inital seeding from random_device
    std::uniform_int_distribution die12{ 1, 12 };
    for(int i = 1 ; i<=10 ; i++){
        std::cout<<die12(mersenneTwister)<<" ";
        if(i % 5 == 0){
            std::cout<<'\n';
        }
    }
}


int main(){
    displayRandomNos();
    rollDie();
    return 0;
}