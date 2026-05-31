#include <atomic>
#include <iostream>

struct SharedData {
  std::atomic_int counter{};
};

void *countWork(void *data) {
  SharedData *sharedData = static_cast<SharedData *>(data);
  for (int i = 0; i < 10; i++) {
    sharedData->counter.fetch_add(1, std::memory_order_relaxed);
  }
  return nullptr;
}

int main(void) {
  pthread_t A;
  pthread_t B;
  SharedData sharedData;

  if (0 != pthread_create(&A, nullptr, countWork, &sharedData)) {
    std::cout << "Thread A cannot be created\n";
  }

  if (0 != pthread_create(&B, nullptr, countWork, &sharedData)) {
    std::cout << "Thread B cannot be created\n";
  }

  pthread_join(A, nullptr);
  pthread_join(B, nullptr);

  std::cout << "The final counter value: " << sharedData.counter << "\n";

  return 0;
}