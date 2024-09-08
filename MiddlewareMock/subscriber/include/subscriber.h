#include "common.h"
#include "payLoad.h"

class subscriber{
 private:
        const char* m_appName;
        void* sharedProcessAdr;
        sem_t* semHnd;
        
        int init();
    public:
        subscriber(const char* appName);        
        int receive();
        ~subscriber();
};