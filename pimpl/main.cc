#include "widget.h"

int main() {
  Widget w1(1);
  const Widget w2(2);
  w1.Draw();
  w2.Draw();
}