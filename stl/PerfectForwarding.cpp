#include <iostream>
#include <utility>

void process(int &value) { std::cout << "L value reference" << std::endl; }

void process(int &&value) { std::cout << "R value reference" << std::endl; }

// universal reference
template <typename T> void logAndForward(T &&value) {
  std::cout << "value received and forwarded to process" << std::endl;
  process(std::forward<T>(value));
}

int main() {
  int x = 10;
  logAndForward(100);
  logAndForward(x);
  logAndForward(std::move(x));
  return 0;
}
