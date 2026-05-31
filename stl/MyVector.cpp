#include <cstddef>

template <typename T> class MyVector {

public:
  MyVector(size_t sizeParam = 0) {
    if (sizeParam > 0) {
      reallocate(sizeParam);
    } else {
      idx = 0;
      max = 0;
      values = nullptr;
    }
  }

  MyVector(const MyVector &vector) {
    if (vector.idx > 0 && nullptr != vector.values) {
      values = new T[vector.max];
      for (size_t index = 0; index < vector.idx; index++) {
        values[index] = vector.values[index];
      }
      idx = vector.idx;
      max = vector.max;
    } else {
      idx = 0;
      max = 0;
      values = nullptr;
    }
  }

  MyVector &operator=(const MyVector &vector) {
    if (this != &vector) {
      if (values != nullptr) {
        delete[] values;
      }
      if (vector.idx > 0 && nullptr != vector.values) {
        values = new T[vector.max];
        for (size_t index = 0; index < vector.idx; index++) {
          values[index] = vector.values[index];
        }
        idx = vector.idx;
        max = vector.max;
      } else {
        idx = 0;
        max = 0;
        values = nullptr;
      }
    }
    return *this;
  }

  MyVector(MyVector &&vector) {
    if (vector.idx > 0 && vector.values != nullptr) {
      values = vector.values;
      idx = vector.idx;
      max = vector.max;

      vector.values = nullptr;
      vector.idx = 0;
      vector.max = 0;
    } else {
      idx = 0;
      max = 0;
      values = nullptr;
    }
  }

  MyVector &operator=(MyVector &&vector) noexcept {
    if (this != &vector) {
      if (values != nullptr) {
        delete[] values;
      }
      if (vector.idx > 0 && vector.values != nullptr) {
        values = vector.values;
        idx = vector.idx;
        max = vector.max;

        vector.values = nullptr;
        vector.idx = 0;
        vector.max = 0;
      } else {
        idx = 0;
        max = 0;
        values = nullptr;
      }
    }
    return *this;
  }

  ~MyVector() {
    if (values != nullptr) {
      delete[] values;
    }
  }

  T &operator[](size_t index) {
    if (nullptr != values && index < idx) {
      return values[index];
    } else {
      // raise an exception
    }
  }

  const T &operator[](size_t index) const {
    if (nullptr != values && index < idx) {
      return values[index];
    } else {
      // raise an exception
    }
  }

  void push_back(const T &value) {
    if (idx >= max) {
      reallocate(max * 2 + 10);
    }
    values[idx++] = value;
  }

  void push_back(T &&value) {
    if (idx >= max) {
      reallocate(max * 2 + 10);
    }
    values[idx++] = value;
  }

  void pop_back() { values[--idx].~T(); }

  size_t size() const { return idx; }

  size_t capacity() const { return max; }

  bool empty() const { return idx == 0; }

  void reserve(size_t newsize) { reallocate(newsize); }

  void clear() {
    if (values != nullptr) {
      for (size_t index = 0; index < idx; index++) {
        values[index].~T();
      }
    }
    idx = 0;
  }

private:
  void reallocate(size_t newSize) {
    if (newSize > 0) {
      // expand
      if (newSize > max) {
        T *newValues = new T[newSize];
        size_t validIdx = idx > newSize ? newSize : idx;
        for (size_t index = 0; index < validIdx; index++) {
          newValues[index] = std::move(values[index]);
        }
        delete[] values;
        values = newValues;
        max = newSize;
      } else {
        // shrink
        if (idx > newSize) {
          for (size_t index = newSize; index < idx; index++) {
            values[index].~T();
          }
          idx = newSize;
        }
        max = newSize;
      }
    } else {
      delete[] values;
      max = idx = 0;
    }
  }

  T *values;
  size_t idx{};
  size_t max{};
};