#include <iostream>

template <typename T> T sum(T value) { return value; }

template <typename T, typename... Args>
decltype(auto) sum(T first, Args... rest) {
  return first + sum(rest...);
}

int main() {
  std::cout << "sum of 7 + 9, 10.5 is " << sum(7, 9, 10.5, 678) << std::endl;
  return 0;
}