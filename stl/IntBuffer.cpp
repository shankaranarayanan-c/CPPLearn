#include <cstddef>
#include <cstring>

class IntBuffer {

public:
  explicit IntBuffer(size_t paramSize) {
    values = new int[paramSize];
    length = paramSize;
  }

  IntBuffer(const IntBuffer &buffer) {
    if (buffer.values != nullptr) {
      values = new int[buffer.size()];
      length = buffer.size();
      std::memcpy(values, buffer.values, length * sizeof(int));
    } else {
      values = nullptr;
      length = 0;
    }
  }

  IntBuffer &operator=(const IntBuffer &buffer) {
    if (this != &buffer) {
      if (values != nullptr) {
        delete[] values;
      }
      values = new int[buffer.size()];
      length = buffer.size();
      std::memcpy(values, buffer.values, length * sizeof(int));
    }
    return *this;
  }

  IntBuffer(IntBuffer &&buffer) : values(buffer.values), length(buffer.length) {
    buffer.values = nullptr;
    buffer.length = 0;
  }

  IntBuffer &operator=(IntBuffer &&buffer) {
    if (this != &buffer) {
      if (values != nullptr) {
        delete[] values;
      }
      values = buffer.values;
      length = buffer.length;
      buffer.values = nullptr;
      buffer.length = 0;
    }
    return *this;
  }

  int &operator[](size_t index) {
    if (values != nullptr) {
      return values[index];
    } else {
      // throw some exception
    }
  }

  const int &operator[](size_t index) const {
    if (values != nullptr) {
      return values[index];
    } else {
      // throw some exception
    }
  }

  int *get() { return values; }

  size_t size() const { return length; }

  ~IntBuffer() {
    if (values != nullptr) {
      delete[] values;
    }
  }

private:
  int *values;
  size_t length;
};