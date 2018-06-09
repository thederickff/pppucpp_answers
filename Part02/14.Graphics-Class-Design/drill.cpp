/*
                            Drill - Chapter 14
  1. Define a class B1 with virtual function vf() and a non-virtual function f().
     Define both of these functions within class B1. Implement each function to
     output its name (e.g, B1::vf()). Make the functions public. Make a B1 object
     and call each function.

  2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf()
     and f() for it.

  3. Define a reference to B1 (a B1&) and initialize that to the D1 object you
     just defined. Call vf() and f() for that reference.

  4. Now define a function called f() for D1 and repeat 1-3. Explain the results.

  5. Add a pure virtual function called pvf() to B1 and try to repeat 1-4.
     Explain the result.

*/
#include <iostream>

class B1
{
public:
  virtual void pvf() = 0;
  virtual void vf();
  void f();
};

class D1 : public B1
{
public:
  void pvf() override;
  void vf() override;
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

void D1::pvf()
{
  std::cout << "D1::pvf()" << std::endl;
}

void D1::vf()
{
  std::cout << "D1::vf()" << std::endl;
}

void D1::f()
{
  std::cout << "D1::f()" << std::endl;
}

int main()
{
  std::cout << "- B1 object -" << std::endl;
  // B1 b1; not initializable has pure virtual function

  // b1.pvf();
  // b1.vf();
  // b1.f();
  std::cout << "- D1 object -" << std::endl;
  D1 d1;

  d1.pvf();
  d1.vf();
  d1.f();
  std::cout << "- B1& to D1 object -" << std::endl;
  B1& br = d1;

  br.pvf();
  br.vf();
  br.f();

  return 0;
}
