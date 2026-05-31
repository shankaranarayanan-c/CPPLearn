#include <atomic>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

struct SharedData {
  int counter;
  std::atomic_bool lock = false;
  pthread_mutex_t mutex;
};

/**
 * Cache Thrashing Version Aggressive
 */
void *spinlockAggressive(void *data) {

  SharedData *sharedData = static_cast<SharedData *>(data);
  while (sharedData->lock.exchange(true, std::memory_order_acquire)) {
    // busy wait usually when the critical section is small
  }
  for (volatile int j = 0; j < 1000000; j++)
    ;
  sharedData->counter++;
  sharedData->lock.store(false, std::memory_order_release);
  return nullptr;
}

/**
 * Optimized Version - Less Backend boud / CPU Stalling
 */
void *spinlockOptimized(void *data) {

  SharedData *sharedData = static_cast<SharedData *>(data);
  while (true) {
    // Read the atomic value without locking and then acquire lock if its
    // available
    if (!sharedData->lock.load(std::memory_order_relaxed)) {
      if (!sharedData->lock.exchange(true, std::memory_order_acquire)) {
        break;
      }
    }
  }
  for (volatile int j = 0; j < 1000000; j++)
    ;
  sharedData->counter++;
  sharedData->lock.store(false, std::memory_order_release);
  return nullptr;
}

void *standardMutex(void *data) {
  SharedData *sharedData = static_cast<SharedData *>(data);
  pthread_mutex_lock(&sharedData->mutex);
  for (volatile int j = 0; j < 1000000; j++)
    ;
  sharedData->counter++;
  pthread_mutex_unlock(&sharedData->mutex);
  return nullptr;
}

void *hybridLock(void *data) {
  SharedData *sharedData = static_cast<SharedData *>(data);
  int lockAquired{0};
  int spinCycle{1000}; // adjust this to find the sweet spot

  // First do busy wait for some time
  for (int i = 0; i < spinCycle; i++) {
    if (!sharedData->lock.exchange(true, std::memory_order_acquire)) {
      lockAquired = 1;
      break;
    }
  }
  // Next do optimized busy wait
  if (lockAquired == 0) {
    for (int i = 0; i < spinCycle; i++) {
      if (!sharedData->lock.load(std::memory_order_relaxed)) {
        if (!sharedData->lock.exchange(true, std::memory_order_acquire)) {
          lockAquired = 2;
          break;
        }
      }
    }
  }

  // Next try the mutex lock
  if (lockAquired == 0) {
    pthread_mutex_lock(&sharedData->mutex);
    lockAquired = 3;
    while (sharedData->lock.exchange(true, std::memory_order_acquire)) {
    }
  }

  if (lockAquired >= 1 && lockAquired <= 3) {
    sharedData->counter++;
    for (volatile int j = 0; j < 1000000; j++)
      ;
    // release first the atomic lock so that the threads in stage 1 or stage 2
    // gets the critical section
    sharedData->lock.store(false, std::memory_order_release);
    if (lockAquired == 3) {
      pthread_mutex_unlock(&sharedData->mutex);
    }
  }

  // switch to mutex
  return nullptr;
}

void printHelp() {
  std::cout
      << "Usage: ./threadsspinlock [1|2|3] \n"
         " 1 = aggressive spinlock \n 2 = optimized spinlock \n 3 = mutex\n 4 "
         "= Hybrid / Adaptable Mutex \n";
  return;
}

int main(int argc, char **argv) {
  if (argc < 2 || !(*argv[1] >= '1' && *argv[1] <= '4')) {
    printHelp();
    return 1;
  }

  SharedData sharedData;
  sharedData.counter = 0;

  constexpr int threadsize = 1000;
  pthread_t thread[threadsize];
  pthread_attr_t thread_attr;
  pthread_attr_init(&thread_attr);
  pthread_attr_setstacksize(&thread_attr, 65536);

  void *(*routine)(void *) = nullptr;
  if (*argv[1] == '1') {
    routine = &spinlockAggressive;
  } else if (*argv[1] == '2') {
    routine = &spinlockOptimized;
  } else if (*argv[1] == '3') {
    pthread_mutex_init(&sharedData.mutex, nullptr);
    routine = &standardMutex;
  } else if (*argv[1] == '4') {
    pthread_mutex_init(&sharedData.mutex, nullptr);
    routine = &hybridLock;
  }

  for (int i = 0; i < threadsize; i++) {
    if (0 != pthread_create(&thread[i], &thread_attr, routine, &sharedData)) {
      std::cout << "Thread creating unsuccessful for " << i << std::endl;
    }
  }

  for (int i = 0; i < threadsize; i++) {
    pthread_join(thread[i], nullptr);
  }

  std::cout << "The output of counter is " << sharedData.counter << "\n";
  pthread_mutex_destroy(&sharedData.mutex);
  return 0;
}