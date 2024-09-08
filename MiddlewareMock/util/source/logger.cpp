#include "logger.h"

void LOG(const char* msg){
    static std::chrono::time_point timeSinceStart{std::chrono::system_clock::now()};
    auto timePointNow = std::chrono::system_clock::now();
    auto duration = (timePointNow - timeSinceStart);
    auto currentTimeMS = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    auto sec = currentTimeMS / 1000;
    auto min = sec / 60;
    if(min > 0){
        sec =  (sec) % (min*60);
    }
    if(sec > 0 || min > 0){
      int totalsec = min * 60 + sec;  
      currentTimeMS = (currentTimeMS) % (totalsec*1000);
    }
    std::cout<<"["<<min<<"m:"<<sec<<"s:"<<currentTimeMS<<"ms] - "<<msg<<'\n';
}
