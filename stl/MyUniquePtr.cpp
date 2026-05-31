template <typename T> class MyUniquePtr {

public:
  MyUniquePtr() : data(nullptr) {}

  MyUniquePtr(T *ptr) : data(ptr) {}

  MyUniquePtr(const MyUniquePtr &) = delete;
  MyUniquePtr &operator=(const MyUniquePtr &) = delete;

  MyUniquePtr(MyUniquePtr &&ptr) : data(ptr.data) { ptr.data = nullptr; }

  MyUniquePtr &operator=(MyUniquePtr &&ptr) noexcept {
    if (this != &ptr) {
      if (nullptr != data) {
        delete data;
      }
      data = ptr.data;
      ptr.data = nullptr;
    }
    return *this;
  }

  ~MyUniquePtr() {
    if (nullptr != data) {
      delete data;
    }
  }

  T &operator*() const {
    if (nullptr != data) {
      return *data;
    } else {
      // raise an exception
    }
  }

  T *operator->() const { return data; }

  T *get() const { return data; }

  T *release() {
    T *temp = data;
    data = nullptr;
    return temp;
  }

  void reset(T *ptr = nullptr) {
    if (data != nullptr) {
      delete data;
    }
    data = ptr;
  }

  explicit bool operator bool() const { return data != nullptr; }

private:
  T *data;
};