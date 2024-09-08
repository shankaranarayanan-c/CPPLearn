#include "subscriber.h"
#include <unistd.h>
#include <csignal>


static bool flag{true};

void signalHandler(int signal){
    if(signal == SIGTERM){
        flag = false;
    }
}

int main(){
    std::string app_name = "receiver1";
    subscriber s1("senderreceiver1");
    subscriber s2("senderreceiver2");
    signal(SIGTERM, signalHandler);
    std::string appName = "subscriber app : " + app_name;
    while(flag){
        sleep(1);
        int data = s1.receive();
        std::string message = appName + " received data : "+std::to_string(data);
        LOG(message.c_str());
        data = s2.receive();
        message = appName + " received data : "+std::to_string(data);
        LOG(message.c_str());
    }

    return EXIT_SUCCESS;

    return 0;
}