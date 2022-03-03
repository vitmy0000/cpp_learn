#include <experimental/propagate_const>
#include <iostream>
#include <memory>

class Widget {
 public:
  void Draw() const;
  void Draw();
  bool Shown() const;

  Widget();
  explicit Widget(int);
  ~Widget();
  Widget(Widget&&);
  Widget(const Widget&) = delete;
  Widget& operator=(Widget&&);
  Widget& operator=(const Widget&) = delete;

 private:
  class WidgetImpl;
  std::experimental::propagate_const<std::unique_ptr<WidgetImpl>> widget_impl_;
};