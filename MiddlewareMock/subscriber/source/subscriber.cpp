#include "subscriber.h"
#include <iostream>
#include <string>

int subscriber::init(){
    int fd = shm_open(m_appName, O_RDONLY, 0600);
    if(fd == -1){
        std::cout<<"subscriber shm open failed \n";
        return -1;
    }
    sharedProcessAdr = mmap(NULL, sizeof(payLoad), PROT_READ, MAP_SHARED, fd, 0);
    if(sharedProcessAdr == MAP_FAILED){
        std::cout<<"subscriber shm mmap failed \n";
        return -1;
    }
    semHnd = sem_open(m_appName, O_EXCL);
    if(semHnd == SEM_FAILED){
        std::cout<<"publisher semaphore opening failed \n";
        return -1;
    }
    return 0;
}

subscriber::subscriber(const char* appName):m_appName{appName}
{
    if(init() == 0){
        LOG("subscriber setup complete!");
    }else{
        LOG("subscriber setup Failed!");
        exit(1);
    }
}

int subscriber::receive(){    
    LOG("subscriber waiting for the data!");
    int data;
    if(sem_wait(semHnd) == 0){
        data = (static_cast<payLoad *>(sharedProcessAdr))->data;
        sem_post(semHnd);
    }
    return data;
}

subscriber::~subscriber(){
    std::string message = "subscriber app : "+ std::string(m_appName) + " cleaning up";
    LOG(message.c_str());
    sem_post(semHnd);
}
