/*
* Write a program to solve quadratic equations.
*/
#include "../std_lib_facilities.h"

int main()
{
  // Call delta the value before to solve x1 or x2
  double a, b, c, delta;
  double x1, x2;
  cout << "Quadratic equation solver" << endl;
  cout << "Enter A" << endl;
  cin >> a;
  cout << "Enter B" << endl;
  cin >> b;
  cout << "Enter C" << endl;
  cin >> c;

  delta = (b*b) - (4 * a * c);
  x1 = (-b - sqrt(delta)) / 2 * a;
  x2 = (-b + sqrt(delta)) / 2 * a;

  cout << "X1: " << x1 << endl;
  cout << "X2: " << x2 << endl;
  return 0;
}
