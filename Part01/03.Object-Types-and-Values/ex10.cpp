/**
* Write a program that takes an operation followed by two operands and outputs the
* result. For example:
* 100 + 3.14
*/
#include "../std_lib_facilities.h"

int main()
{

  double n1, n2, r;
  char operand;

  cout << "Enter two numbers followed by an operand in the middle separated by space (such as 20 + 30)" << endl;
  cin >> n1 >> operand >> n2;

  if (operand == '+')
    r = n1 + n2;
  else if (operand == '-')
    r = n1 - n2;
  else if (operand == '*')
    r = n1 * n2;
  else if (operand == '/')
    r = n1 / n2;
  else
    simple_error("Operand written is wrong!");

  cout << r << endl;
  return 0;
}
