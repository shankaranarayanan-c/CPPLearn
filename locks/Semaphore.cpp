#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

struct SharedData {
  sem_t writeEnable;
  sem_t readEnable;
  int buffer[10]{};
  int data{};
  int writeIdx{};
  int readIdx{};
  pthread_mutex_t producerMutex;
  pthread_mutex_t consumerMutex;
};

struct SharedDataProducer {};

struct SharedDataConsumer {};

void *producerWorker(void *data) {
  SharedData *sharedData = static_cast<SharedData *>(data);
  int sentValue{};
  while (true) {
    sem_wait(&sharedData->writeEnable);
    pthread_mutex_lock(&sharedData->producerMutex);
    if (sharedData->data == 25) {
      pthread_mutex_unlock(&sharedData->producerMutex);
      sem_post(&sharedData->writeEnable);
      break;
    }
    sharedData->buffer[sharedData->writeIdx++] = ++sharedData->data;
    sharedData->writeIdx = sharedData->writeIdx % 10;
    std::cout << "Thread " << pthread_self()
              << " Sent data: " << sharedData->data << "\n";
    // sleep(1);
    pthread_mutex_unlock(&sharedData->producerMutex);
    sem_post(&sharedData->readEnable);
  }
  std::cout << "Producer Thread " << pthread_self() << " exited \n";
  return nullptr;
}

void *consumerWorker(void *data) {
  SharedData *sharedData = static_cast<SharedData *>(data);
  while (true) {
    sem_wait(&sharedData->readEnable);
    pthread_mutex_lock(&sharedData->consumerMutex);
    std::cout << "Thread " << pthread_self()
              << " Consumed data: " << sharedData->buffer[sharedData->readIdx]
              << "\n";
    if (sharedData->buffer[sharedData->readIdx] == 25) {
      pthread_mutex_unlock(&sharedData->consumerMutex);
      sem_post(&sharedData->readEnable);
      break;
    }
    sharedData->readIdx++;
    sharedData->readIdx = sharedData->readIdx % 10;
    pthread_mutex_unlock(&sharedData->consumerMutex);
    sleep(1);

    sem_post(&sharedData->writeEnable);
  }
  std::cout << "Consumer Thread " << pthread_self() << " exited \n";

  return nullptr;
}

int main(void) {
  SharedData sharedData;
  sem_init(&sharedData.readEnable, 0, 0);
  sem_init(&sharedData.writeEnable, 0, 10);
  pthread_mutex_init(&sharedData.producerMutex, nullptr);
  pthread_mutex_init(&sharedData.consumerMutex, nullptr);
  int totalProducers = 2;
  int totalConsumers = 2;

  pthread_t consumerThread[totalConsumers];
  pthread_t producerThread[totalProducers];

  for (int i = 0; i < totalConsumers; i++) {
    pthread_create(&consumerThread[i], nullptr, consumerWorker, &sharedData);
  }

  for (int i = 0; i < totalProducers; i++) {
    pthread_create(&producerThread[i], nullptr, producerWorker, &sharedData);
  }

  for (int i = 0; i < totalProducers; i++) {
    pthread_join(producerThread[i], nullptr);
  }

  for (int i = 0; i < totalConsumers; i++) {
    pthread_join(consumerThread[i], nullptr);
  }

  sem_close(&sharedData.readEnable);
  sem_close(&sharedData.writeEnable);
  return 0;
}