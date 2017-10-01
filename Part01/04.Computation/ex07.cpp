/*
* Modify the 'mini calculator' from exercise 5 to accept (just) single-digit
* numbers written as either digits or spelled-out.
*/
#include "../std_lib_facilities.h"

int main()
{
  double n1 = -1, n2 = -1, result;
  char operation;
  vector<string> soNumbers = {"zero", "one", "two", "three", "four", "five",
  "six", "seven", "eight", "nine"};
  string number1, number2;
  cout << "Calculator. Enter a number, an operation and then another number, such as (four * five)" << endl;
  cin >> number1 >> operation >> number2;
  for (int i = 0; i < soNumbers.size(); i++) {
    if(soNumbers[i] == number1) {
      n1 = i;
    }
    if(soNumbers[i] == number2) {
      n2 = i;
    }
  }

  if (n1 == -1 || n2 == -1) {
    simple_error("You entered a unknown spelled-out number");
  }

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
