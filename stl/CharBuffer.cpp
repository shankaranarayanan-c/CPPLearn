#include <cstddef>
#include <cstring>

class CharBuffer {

public:
  CharBuffer(const char *string = "") {
    if (nullptr == string) {
      value = nullptr;
      length = 0;
    } else {
      size_t index{0};
      while ('\0' != string[index]) {
        index++;
      }
      value = new char[index + 1];
      std::memcpy(value, string, index);
      length = index;
      value[index] = '\0';
    }
  }

  CharBuffer(const CharBuffer &buffer) {
    if (nullptr == buffer.value) {
      value = nullptr;
      length = 0;
    } else {
      length = buffer.length;
      value = new char[length + 1];
      std::memcpy(value, buffer.value, length);
      value[length] = '\0';
    }
  }

  CharBuffer &operator=(const CharBuffer &buffer) {
    if (this != &buffer) {
      if (nullptr != value) {
        delete[] value;
      }
      length = buffer.length;
      value = new char[length + 1];
      std::memcpy(value, buffer.value, length);
      value[length] = '\0';
    }
    return *this;
  }

  CharBuffer(CharBuffer &&buffer) : value(buffer.value), length(buffer.length) {
    buffer.value = nullptr;
    buffer.length = 0;
  }

  CharBuffer &operator=(CharBuffer &&buffer) noexcept {
    if (this != &buffer) {
      if (nullptr != value) {
        delete[] value;
      }
      length = buffer.length;
      value = buffer.value;
      buffer.length = 0;
      buffer.value = nullptr;
    }
    return *this;
  }

  ~CharBuffer() {
    if (nullptr != value) {
      delete[] value;
    }
  }

  char &operator[](size_t index) {
    if (nullptr != value && index < length) {
      return value[index];
    } else {
      // throw exception or cassert
    }
  }

  const char &operator[](size_t index) const {
    if (nullptr != value && index < length) {
      return value[index];
    } else {
      // throw exception or cassert
    }
  }

  CharBuffer operator+(const CharBuffer &buffer) const {
    CharBuffer tmpBuffer;
    tmpBuffer.length = length + buffer.length;
    tmpBuffer.value = new char[tmpBuffer.length + 1];
    if (nullptr != value) {
      std::memcpy(tmpBuffer.value, value, length);
    }
    if (nullptr != buffer.value) {
      std::memcpy(tmpBuffer.value + length, buffer.value, buffer.length);
    }
    tmpBuffer.value[tmpBuffer.length] = '\0';
    return tmpBuffer;
  }

  CharBuffer &operator+=(const CharBuffer &buffer) {
    size_t tmpLength = length;
    char *tmpValue = value;
    length = tmpLength + buffer.length;
    value = new char[length + 1];
    if (nullptr != tmpValue) {
      std::memcpy(value, tmpValue, tmpLength);
    }
    if (nullptr != buffer.value) {
      std::memcpy(value + tmpLength, buffer.value, buffer.length);
    }
    value[length] = '\0';
    if (nullptr != tmpValue) { // do the deletion later for a+=a
      delete[] tmpValue;
    }
    return *this;
  }

private:
  char *value;
  size_t length;
};