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

  6. Define a class D2 derived from D1 and override pvf() in D2. Make an object
     of class D2 and invoke f(), vf(), and pvf() for it.

  7. Define a class B2 with a pure virtual function pvf(). Define a class D21
     with a string data member and a member function that overrides pvf();
     D21::pvf() should output the value of the string. Define a class D22 that
     is just like D21 except that its data member is an int. Define function f()
     that takes a B2& argument and calls pvf() for its argument. Call f() with a
     D21 and a D22.

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

class D2 : public D1
{
public:
  void pvf() override;
};

class B2
{
public:
  virtual void pvf() = 0;
};

class D21 : public B2
{
public:
  D21();

  void pvf() override;
private:
  std::string member;
};

class D22 : public B2
{
public:
  D22();

  void pvf() override;
private:
  int member;
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

void D2::pvf()
{
  std::cout << "D2::pvf()" << std::endl;
}

D21::D21()
: member("D21's string")
{
}

void D21::pvf()
{
    std::cout << member << std::endl;
}

D22::D22()
: member(2222)
{
}

void D22::pvf()
{
  std::cout << member << std::endl;
}

void f(B2& b2)
{
  b2.pvf();
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

  std::cout << "- D2 object -" << std::endl;
  D2 d2;

  d2.pvf();
  d2.vf();
  d2.f();
  std::cout << "- B2 objects -" << std::endl;
  D21 d21;
  D22 d22;
  f(d21);
  f(d22);

  return 0;
}
