#include <experimental/propagate_const>
#include <iostream>
#include <memory>

class Widget {
 public:
  void Draw() const;  // public API that will be forwarded to the implementation
  void Draw();
  bool Shown() const {
    return true;
  }  // public API that implementation has to call

  Widget();  // even the default ctor needs to be defined in the implementation
             // file Note: calling draw() on default constructed object is UB
  explicit Widget(int);
  ~Widget();  // defined in the implementation file, where impl is a complete
              // type
  Widget(Widget&&);  // defined in the implementation file
                     // Note: calling draw() on moved-from object is UB
  Widget(const Widget&) = delete;
  Widget& operator=(Widget&&);  // defined in the implementation file
  Widget& operator=(const Widget&) = delete;

 private:
  class WidgetImpl;
  std::experimental::propagate_const<std::unique_ptr<WidgetImpl>> widget_impl_;
};