#include <cstring>
#include <iostream>
#include <utility>

class MyString {
 public:
  // default constructor
  MyString() : data_(nullptr), len_(0) {}

  // constructor
  MyString(const char* p) : len_(std::strlen(p)) {
    std::cout << "constructor" << std::endl;
    InitData(p);
  }

  // copy constructor
  MyString(const MyString& str) : len_(str.len_) {
    std::cout << "copy constructor" << std::endl;
    InitData(str.data_);
  }

  // move constructor
  MyString(MyString&& str) noexcept : data_(str.data_), len_(str.len_) {
    std::cout << "move constructor" << std::endl;
    str.len_ = 0;
    str.data_ = nullptr;
  }

  // copy assignment
  MyString& operator=(const MyString& str) {
    std::cout << "copy assignment" << std::endl;
    // check self assignment
    if (this != &str) {
      if (data_) {
        delete data_;
      }
      len_ = str.len_;
      InitData(str.data_);
    }
    return *this;
  }

  // move assignment
  MyString& operator=(MyString&& str) noexcept {
    std::cout << "move assignment" << std::endl;
    // check self assignment
    if (this != &str) {
      if (data_) {
        delete data_;
      }
      len_ = str.len_;
      data_ = str.data_;
      str.len_ = 0;
      str.data_ = nullptr;
    }
    return *this;
  }

  // destructor
  ~MyString() {
    if (data_) {
      delete data_;
    }
  }

 private:
  char* data_;
  size_t len_;
  void InitData(const char* s) {
    data_ = new char[len_ + 1];
    std::memcpy(data_, s, len_);
    data_[len_] = '\0';
  }
};

void foo(const MyString&) {
  std::cout << "foo with const ref" << std::endl;
}

void foo(MyString&&) {
  std::cout << "foo with rvalue ref" << std::endl;
}

void bar(MyString) {
  std::cout << "bar" << std::endl;
}

MyString bax() {
  MyString s("abcd");
  return s;
}

int main(int argc, char* argv[]) {
  MyString s1 = bax();

  std::cout << "===== foo =====" << std::endl;
  foo(s1);               // const ref
  foo(std::move(s1));    // rvalue ref
  foo(MyString("abc"));  // rvalue ref

  std::cout << "===== bar =====" << std::endl;
  bar(s1);               // copy constructor
  bar(std::move(s1));    // move constructor
  bar(MyString("abc"));  // copy elison
}

// 如果只读： const T&
// 如果实现需要copy：
//  1. const T& + T&&. 可能通过move把copy优化，需要调用者使用std::move()
//  2. T. 多一次参数的move.
//  但是需不需要两个版本的函数，取舍于函数是否复杂，是否有多个参数