#include "publisher.h"
#include <iostream>

int publisher::init(){
    int fd = shm_open(m_appName, O_CREAT | O_EXCL | O_RDWR, 0600);
    if(fd == -1){
        std::cout<<"publisher shm open failed \n";
        return -1;
    }
    int ft = ftruncate(fd, sizeof(payLoad));
    if(ft == -1){
        std::cout<<"publisher shm ftruncate failed \n";
        return -1;
    }
    sharedProcessAdr = mmap(NULL, sizeof(payLoad), PROT_WRITE, MAP_SHARED, fd, 0);
    if(sharedProcessAdr == MAP_FAILED){
        std::cout<<"publisher shm mmap failed \n";
        return -1;
    }

    semHnd = sem_open(m_appName, O_CREAT | O_EXCL,0600,1);
    if(semHnd == SEM_FAILED){
        std::cout<<"publisher semaphore opening failed \n";
        return -1;
    }
    return 0;
}


publisher::publisher(const char* appName):m_appName{appName}
{
    if(init() == 0){
        LOG("publisher setup complete!");
    }else{
        LOG("publisher setup Failed!");
        exit(1);
    }
}

int publisher::send(int data){
    if(sem_wait(semHnd) == 0){
        (static_cast<payLoad *>(sharedProcessAdr))->data = data;
        sem_post(semHnd);
    }
    return 0;
}

publisher::~publisher(){
    std::string message = "publisher app : "+ std::string(m_appName) + " cleaning up";
    LOG(message.c_str());
    sem_post(semHnd);
    shm_unlink(m_appName);
    sem_unlink(m_appName);
}