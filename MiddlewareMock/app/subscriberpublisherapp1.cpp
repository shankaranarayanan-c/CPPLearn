#include "subscriber.h"
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
    std::string app_name = "senderreceiver1";
    publisher p(app_name.c_str());
    subscriber s("sender1");
    signal(SIGTERM, signalHandler);
    std::string appName = "subscriber app : " + app_name;
    while(flag){
        sleep(1);
        int data = s.receive();
        std::string message = appName + " received data : "+std::to_string(data);
        LOG(message.c_str());
        p.send(data);
        message = appName + " sent data : "+std::to_string(data);
        LOG(message.c_str());
    }

    return EXIT_SUCCESS;

    return 0;
}