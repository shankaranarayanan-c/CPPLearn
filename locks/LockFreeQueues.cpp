#include <atomic>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

struct alignas(std::hardware_destructive_interference_size) Data {
  int value;
  std::atomic_int state{0};
};

struct HPBuffer {
  Data data[16];
  std::atomic_size_t writeIdx{};
  std::atomic_size_t readIdx{};
};

std::atomic<bool> keepRunning{true};

void *producerWorker(void *data) {
  static thread_local int counter{};

  while (keepRunning) {
    HPBuffer *buffer = static_cast<HPBuffer *>(data);

    // get the index
    size_t index =
        buffer->writeIdx.fetch_add(1, std::memory_order_relaxed) & 15;
    int expected = 0;
    while (!buffer->data[index].state.compare_exchange_weak(
        expected, 1, std::memory_order_acquire)) {
      expected = 0;
      if (!keepRunning) {
        return nullptr;
      }
    }
    buffer->data[index].value = ++counter;
    buffer->data[index].state.store(2, std::memory_order_release);
    std::cout << "Producer Thread " << pthread_self() << " sent value "
              << counter << std::endl;
    if (counter > 50) {
      break;
    }
  }
  std::cout << "Producer Thread " << pthread_self() << " Exited!" << std::endl;
  return nullptr;
}

void *consumerWorker(void *data) {
  while (keepRunning) {
    HPBuffer *buffer = static_cast<HPBuffer *>(data);

    // get the index
    size_t index = buffer->readIdx.fetch_add(1, std::memory_order_relaxed) & 15;
    int expected = 2;
    while (!buffer->data[index].state.compare_exchange_weak(
        expected, 3, std::memory_order_acquire)) {
      expected = 2;
      if (!keepRunning) {
        return nullptr;
      }
    }
    int value = buffer->data[index].value;
    buffer->data[index].state.store(0, std::memory_order_release);
    std::cout << "Consumer Thread " << pthread_self() << " received value "
              << value << std::endl;
    if (value > 50) {
      keepRunning = false;
      for (int i = 0; i < 16; i++) {
        buffer->data[i].state.store(2, std::memory_order_release);
        buffer->data[i].state.store(0, std::memory_order_release);
      }
    }
  }
  std::cout << "Consumer Thread " << pthread_self() << " Exited!<< std::endl";

  return nullptr;
}

int main(void) {
  HPBuffer buffer;
  int totalProducers = 2;
  int totalConsumers = 2;

  pthread_t consumerThread[totalConsumers];
  pthread_t producerThread[totalProducers];

  for (int i = 0; i < totalConsumers; i++) {
    pthread_create(&consumerThread[i], nullptr, consumerWorker, &buffer);
  }

  for (int i = 0; i < totalProducers; i++) {
    pthread_create(&producerThread[i], nullptr, producerWorker, &buffer);
  }

  for (int i = 0; i < totalProducers; i++) {
    pthread_join(producerThread[i], nullptr);
  }

  for (int i = 0; i < totalConsumers; i++) {
    pthread_join(consumerThread[i], nullptr);
  }

  return 0;
}