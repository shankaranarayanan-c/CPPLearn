#include "publisher.h"
#include <unistd.h>
#include <csignal>

static bool flag{true};

void signalHandler(int signal){
    if(signal == SIGTERM){
        flag = false;
    }
}

int main(){
    std::string app_name = "sender1";
    publisher p(app_name.c_str());
    signal(SIGTERM, signalHandler);
    std::string appName = "publisher app : " + app_name;
    int data=0;
   
    while(flag){
         sleep(1);
         p.send(data);
         std::string message = appName +" sent data : "+std::to_string(data);
         LOG(message.c_str());
         data++;
    }

    return 0;
}