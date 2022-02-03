#include <typeinfo>
#include <iostream>

int main()
{
  std::cout << typeid(1.0).name() << std::endl;
}

/*
For better output type display:
./main | c++filt --types
*/