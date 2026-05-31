#include <iostream>
#include <pthread.h>
#include <unistd.h>

struct SharedData {
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  bool signal{false};
};

void *work(void *data) {
  SharedData *sharedData = static_cast<SharedData *>(data);
  pthread_mutex_lock(&sharedData->mutex);
  while (!sharedData->signal) {
    pthread_cond_wait(&sharedData->cond, &sharedData->mutex);
  }
  sleep(2);
  std::cout << "Thread Executed!\n";
  pthread_mutex_unlock(&sharedData->mutex);
  return nullptr;
}

void *signaller(void *data) {
  SharedData *sharedData = static_cast<SharedData *>(data);
  pthread_mutex_lock(&sharedData->mutex);
  sleep(5);
  sharedData->signal = true;
  pthread_cond_broadcast(&sharedData->cond);
  pthread_mutex_unlock(&sharedData->mutex);
  return nullptr;
}

int main(void) {
  SharedData data;
  pthread_mutex_init(&data.mutex, nullptr);
  pthread_cond_init(&data.cond, nullptr);

  pthread_t thread1;
  pthread_create(&thread1, nullptr, work, &data);
  pthread_t thread2;
  pthread_create(&thread2, nullptr, work, &data);
  pthread_t thread3;
  pthread_create(&thread3, nullptr, work, &data);

  pthread_t signalThread;
  pthread_create(&signalThread, nullptr, signaller, &data);

  pthread_join(thread1, nullptr);
  pthread_join(thread2, nullptr);
  pthread_join(thread3, nullptr);
  pthread_join(signalThread, nullptr);

  pthread_mutex_destroy(&data.mutex);
  pthread_cond_destroy(&data.cond);

  return 0;
}