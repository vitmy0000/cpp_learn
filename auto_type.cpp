#include <iostream>

template <typename T>  // declaration only for TD;
class TD;              // TD == "Type Displayer"

int main() {
  const int i = 5;
  auto& x = i;
  // TD<decltype(x)> xType;  // elicit errors containing
}