/*
  1. Define a class B1 with virtual function vf() and a non-virtual function f().
     Define both of these functions within class B1. Implement each function to
     output its name (e.g, B1::vf()). Make the functions public. Make a B1 object
     and call each function.
*/
#include <iostream>

class B1
{
public:
  virtual void vf();
  void f();
};

void B1::vf()
{
  std::cout << "B1::vf()" << std::endl;
}

void B1::f()
{
  std::cout << "B1::f()" << std::endl;
}

int main()
{
  B1 b1;

  b1.vf();
  b1.f();

  return 0;
}
