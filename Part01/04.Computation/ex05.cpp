/*
* Write a program that performs as a very simple calculator. Your calculator should
* be able to handle the four basic math operations. Your program should prompt
* the user to enteer three arguments: two doubles values and a character to represent
* an operation.
*/
#include "../std_lib_facilities.h"

int main()
{
  double n1, n2, result;
  char operation;

  cout << "Calculator. Enter a number, an operation and then another number, such as (4 * 5)" << endl;
  cin >> n1 >> operation >> n2;

  switch (operation) {
    case '+':
      result = n1 + n2;
      break;
    case '-':
      result = n1 - n2;
      break;
    case '*':
      result = n1 * n2;
      break;
    case '/':
      result = n1 / n2;
      break;
    default:
      simple_error("You entered a unknown operation type");
  }

  cout << result << endl;
  return 0;
}
