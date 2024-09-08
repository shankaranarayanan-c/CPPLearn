#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "common.h"
#include "payLoad.h"

class publisher{
    private:
        const char* m_appName;
        void* sharedProcessAdr;
        sem_t* semHnd;
        
        int init();

    public:
        publisher(const char* appName);        
        int send(int data);
        ~publisher();
};

#endif