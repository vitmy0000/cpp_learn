#include <iostream>
#include <memory>

class A {
 public:
  virtual void DoFoo() const {
    std::cout << "A do foo" << std::endl;
  }
  virtual ~A() = default;

 private:
  int val_;
};

class SubA : public A {
 public:
  virtual void DoFoo() const override final {
    std::cout << "SubA do foo" << std::endl;
  }
  virtual ~SubA() = default;

 private:
  int val_;
};

int main() {
  std::shared_ptr<A> a = std::make_shared<SubA>();
  a->DoFoo();
}