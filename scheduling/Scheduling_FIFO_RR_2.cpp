#include <chrono>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

void *work1(void *arg) {
  auto start = std::chrono::steady_clock::now();
  bool isDisplayed = false;
  int16_t timeCount{0};
  while (std::chrono::steady_clock::now() - start < std::chrono::seconds(5)) {
    if (std::chrono::steady_clock::now() - start >
            std::chrono::seconds(timeCount) &&
        !isDisplayed) {
      std::cout << "Thread1 is executing!\n";
      isDisplayed = true;
      timeCount++;
    } else {
      isDisplayed = false;
    }
  }
  std::cout << "Thread1 execution completed!\n";
  return nullptr;
}

void *work2(void *arg) {
  auto start = std::chrono::steady_clock::now();
  int16_t timeCount{0};
  bool isDisplayed = false;

  while (std::chrono::steady_clock::now() - start < std::chrono::seconds(5)) {
    if (std::chrono::steady_clock::now() - start >
            std::chrono::seconds(timeCount) &&
        !isDisplayed) {
      std::cout << "Thread2 is executing!\n";
      isDisplayed = true;
      timeCount++;
    } else {
      isDisplayed = false;
    }
  }
  std::cout << "Thread2 execution completed!\n";
  return nullptr;
}

int main() {
  pthread_t thread1, thread2;
  pthread_attr_t thread1attr, thread2attr;

  pthread_attr_init(&thread1attr);
  pthread_attr_init(&thread2attr);

  pthread_attr_setschedpolicy(&thread1attr, SCHED_FIFO);
  pthread_attr_setschedpolicy(&thread2attr, SCHED_RR);

  struct sched_param schedparam1;
  schedparam1.sched_priority = 50;
  struct sched_param schedparam2;
  schedparam2.sched_priority = 70;
  pthread_attr_setschedparam(&thread1attr, &schedparam1);
  pthread_attr_setschedparam(&thread2attr, &schedparam2);

  cpu_set_t cpuattr1, cpuattr2;
  CPU_ZERO(&cpuattr1);
  CPU_ZERO(&cpuattr2);
  CPU_SET(7, &cpuattr1);
  CPU_SET(7, &cpuattr2);
  pthread_attr_setaffinity_np(&thread1attr, sizeof(cpuattr1), &cpuattr1);
  pthread_attr_setaffinity_np(&thread2attr, sizeof(cpuattr2), &cpuattr2);

  pthread_attr_setinheritsched(&thread1attr, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setinheritsched(&thread2attr, PTHREAD_EXPLICIT_SCHED);

  if (pthread_create(&thread1, &thread1attr, work1, nullptr) != 0) {
    std::cout << "Unable to create Thread1\n";
  }

  sleep(1);

  if (pthread_create(&thread2, &thread2attr, work2, nullptr) != 0) {
    std::cout << "Unable to create Thread2\n";
  }

  pthread_join(thread1, nullptr);
  pthread_join(thread2, nullptr);

  return 0;
}