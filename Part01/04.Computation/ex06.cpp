/*
* Make a vector holding the ten string 'zero', 'one' ... 'nine'. Use that in a
* program that converts a digit to its corresponding spelled-out value.
*/
#include "../std_lib_facilities.h"

int main()
{
  vector<string> soNumbers = {"zero", "one", "two", "three", "four", "five",
  "six", "seven", "eight", "nine"};

  int number;
  cout << "Enter a number between 1 and 10: " << endl;
  while(cin >> number) {
    if(number > 10 || number < 0) {
      simple_error("You entered a unknown number.");
    }
    cout << soNumbers[number] << endl;
  }

  return 0;
}
