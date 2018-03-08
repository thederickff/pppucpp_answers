/*
  Can we declare a non-reference function argument const
  (e.g. void f(const int);)? What might it mean? Why might we want to do that?
  Why don't people do that often? Try it; write a couple of small programs to
  see what works.

  Yes, it is pretty much like creating a local constant, but with undefined
  initialization. Because in some cases it may be unnecessary, or some people
  don't know it could be possible.
*/
#include "../std_lib_facilities.h"

void f(const int a)
{
  if (a > 10) return;
  f(a+1);
  cout << "A: " << a << '\n';
}

void aProgression(int n1, const int r)
{
  if (n1 > r*100) return;
  aProgression(n1+r, r);
  cout << "n1: " << n1 << ", r: " << r << '\n';
}


int main()
{
  int i = 0;

  f(i);
  cout << "\n\n###########################\n\n";
  aProgression(12, 3);

  return 0;
}
