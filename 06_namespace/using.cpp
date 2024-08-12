#include<iostream>

using namespace std;            // it may lead to ambiguity as it introduces all the identifiers locally which can collide with existing identifiers

void cout(){
    cout<<"hi \n";
}

int main(){
    return 0;
}