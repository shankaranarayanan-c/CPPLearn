#include <iostream>
#include <cstring>

class UserString{
    char* string = nullptr;
    uint length;

public:

    UserString(const char* string){
        uint index = 0;
        while(string[index] != '\0'){
            index++;
        }
        index++;
        this->string = new char[index];
        length = index;
        std::memcpy(this->string,string,index);
    }

    UserString(const char* string, uint length){
        if(this->string != nullptr){
            delete this->string;
        }
        this->string = new char[length];
        std::memcpy(this->string, string, length);
        this->length = length;
    }

    ~UserString(){
        delete string;
    }

    // copy constructor
    UserString(const UserString& us) : UserString(us.string, us.length){

    }

    //move constructor
    UserString(UserString&& us){
        if(this->string != nullptr){
            delete this->string;
        }
        this->string = us.string;
        this->length = us.length;
        us.string = nullptr;
    }

    //assignment copy operator
    void operator=(const UserString& us) {
        if(this->string != nullptr){
            delete this->string;
        }
        this->string = new char[us.length];
        std::memcpy(this->string, us.string, us.length);
        this->length = us.length;
    }

    //assignment move operator
    void operator=(UserString&& us) {
        if(this->string != nullptr){
            delete this->string;
        }
        this->string = us.string;
        this->length = us.length;
        us.string = nullptr;
    }

    void display(){
        std::cout<<string<<'\n';
    }
};

int main()
{
    UserString us("Hello World!");
    us.display();
    UserString us1(us);
    us1.display();
    UserString us2 = us1;
    us2.display();
    UserString us3("Hi");
    us1 = us3;
    us1.display();
    UserString us4(std::move(us));
    us4.display();
    // std::cout<<"UB\n";
    // us.display();
    // std::cout<<"UB over\n";
    us2 = std::move(us4);
    us2.display();
    return 0;
}