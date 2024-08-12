int foo(){
    int y;
    char y;         // violation of ODR
}

int foo(){          // violation of ODR
    int x;
}

int main(){
    int x;          // x is local to main not 
}