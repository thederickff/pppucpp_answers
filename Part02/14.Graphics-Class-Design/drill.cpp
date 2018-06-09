/*
  1. Define a class B1 with virtual function vf() and a non-virtual function f().
     Define both of these functions within class B1. Implement each function to
     output its name (e.g, B1::vf()). Make the functions public. Make a B1 object
     and call each function.

  2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf()
     and f() for it.
*/
#include <iostream>

class B1
{
public:
  virtual void vf();
  void f();
};

class D1 : public B1
{
public:
  void vf() override;
};

void B1::vf()
{
  std::cout << "B1::vf()" << std::endl;
}

void B1::f()
{
  std::cout << "B1::f()" << std::endl;
}

void D1::vf()
{
  std::cout << "D1::vf()" << std::endl;
}

int main()
{
  B1 b1;

  b1.vf();
  b1.f();

  D1 d1;

  d1.vf();
  d1.f();

  return 0;
}
