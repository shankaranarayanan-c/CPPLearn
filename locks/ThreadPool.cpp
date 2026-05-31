#include <iostream>
#include <pthread.h>
#include <unistd.h>

struct Task {
  void *(*work)(int data);
};

void *work1(int data) {
  sleep(1);
  std::cout << "Task " << data << " Work1 done by " << pthread_self() << "\n";
  return nullptr;
}

void *work2(int data) {
  sleep(2);
  std::cout << "Task " << data << " Work2 done by " << pthread_self() << "\n";
  return nullptr;
}

class ThreadPool {
public:
  ThreadPool(int threadSize) : totalThreads(threadSize) {
    pthread_mutex_init(&mutex, nullptr);
    pthread_cond_init(&threadCond, nullptr);
    for (int i = 0; i < totalThreads; i++) {
      pthread_create(&threads[i], nullptr, &ThreadPool::routineBootStrap, this);
    }
  }

  static void *routineBootStrap(void *context) {
    return (static_cast<ThreadPool *>(context))->routine();
  }

  void *routine(void) {
    while (true) {
      pthread_mutex_lock(&mutex);
      while (!exit && taskCounter >= taskIdx) {
        pthread_cond_wait(&threadCond, &mutex);
      }
      if (exit && taskCounter >= taskIdx) {
        pthread_mutex_unlock(&mutex);
        break;
      }
      Task task = tasks[taskCounter];
      int taskno = taskCounter;
      taskCounter++;
      pthread_mutex_unlock(&mutex);
      task.work(taskno);
    }
    return nullptr;
  }

  void addTask(void *(*func)(int)) {
    pthread_mutex_lock(&mutex);
    if (taskIdx < 20) {
      tasks[taskIdx].work = func;
      taskIdx++;
      pthread_cond_signal(&threadCond);
    }
    pthread_mutex_unlock(&mutex);
  }

  ~ThreadPool() {
    pthread_mutex_lock(&mutex);
    exit = true;
    pthread_cond_broadcast(&threadCond);
    pthread_mutex_unlock(&mutex);
    for (int i = 0; i < totalThreads; i++) {
      pthread_join(threads[i], nullptr);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&threadCond);
  }

private:
  Task tasks[20];
  int taskIdx{};
  int totalThreads;
  pthread_t threads[10];
  pthread_mutex_t mutex;
  pthread_cond_t threadCond;
  bool exit{false};
  int taskCounter{};
};

int main(void) {
  ThreadPool threadPool(4);
  for (int i = 0; i < 20; i += 2) {
    threadPool.addTask(work1);
    threadPool.addTask(work2);
  }
  return 0;
}
