#include <cassert>
#include <cstddef>

template <typename T> class MySharedPtr {

public:
  MySharedPtr(T *obj) {
    if (nullptr != obj) {
      create(obj);
    } else {
      targetObj = nullptr;
      count = nullptr;
    }
  }

  MySharedPtr(const MySharedPtr &obj) {
    update(obj);
    if (nullptr != count) {
      (*count)++;
    }
  }

  MySharedPtr &operator=(const MySharedPtr &obj) {
    if (this != &obj) {
      release();
      update(obj);
      if (nullptr != count) {
        (*count)++;
      }
    }
    return *this;
  }

  MySharedPtr(MySharedPtr &&obj) {
    update(obj);
    invalidate(obj);
  }

  MySharedPtr &operator=(MySharedPtr &&obj) {
    if (this != &obj) {
      release();
      update(obj);
      invalidate(obj);
    }
    return *this;
  }

  void reset(T *obj = nullptr) {
    release();
    if (nullptr != obj) {
      create(obj);
    } else {
      targetObj = nullptr;
      count = nullptr;
    }
  }

  T *get() { return targetObj; }

  ~MySharedPtr() { release(); }

private:
  void create(T *obj) {
    targetObj = obj;
    count = new size_t(1);
  }

  void invalidate(MySharedPtr &obj) { obj.count = obj.targetObj = nullptr; }

  void update(const MySharedPtr &obj) {
    targetObj = obj.targetObj;
    count = obj.count;
  }

  void release() {
    if (nullptr != count) {
      (*count)--;
      if ((*count) == 0) {
        delete count;
        delete targetObj;
        count = nullptr;
        targetObj = nullptr;
      }
    }
  }

  T *targetObj;
  size_t *count;
};