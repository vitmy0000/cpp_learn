#include "widget.h"

class Widget::WidgetImpl {
 public:
  void Draw(const Widget& w) const {
    // back-reference
    if (w.Shown()) {
      std::cout << "drawing a const Widget " << num_ << '\n';
    }
  }

  void Draw(const Widget& w) {
    if (w.Shown()) {
      std::cout << "drawing a non-const Widget " << num_ << '\n';
    }
  }

  WidgetImpl(int num) : num_(num) {}

 private:
  int num_;
};

void Widget::Draw() const {
  widget_impl_->Draw(*this);
}
void Widget::Draw() {
  widget_impl_->Draw(*this);
}
bool Widget::Shown() const {
    return true;
}
Widget::Widget() = default;
Widget::Widget(int num) : widget_impl_{std::make_unique<WidgetImpl>(num)} {}
Widget::Widget(Widget&&) = default;
Widget::~Widget() = default;
Widget& Widget::operator=(Widget&&) = default;