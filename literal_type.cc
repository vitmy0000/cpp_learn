#include <iostream>
#include <typeinfo>

int main() {
  std::cout << typeid(1.0f).name() << std::endl;
  std::cout << typeid(1.0).name() << std::endl;
}

/*
For better output type display:
./main | c++filt --types
*/