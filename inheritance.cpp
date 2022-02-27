#include <iostream>
#include <memory>

class A {
 public:
  virtual void DoFoo() const {
    std::cout << "A do foo" << std::endl;
  }
  void DoBar() const {
    std::cout << "val: " << val_ << std::endl;
    std::cout << "A do bar" << std::endl;
    DoFoo();
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
};

int main() {
  std::shared_ptr<A> a = std::make_shared<SubA>();
  a->DoBar();
}