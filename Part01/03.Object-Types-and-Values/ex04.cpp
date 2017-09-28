/**
* Write a program that prompts the user to enter two integer. Store these values
* in int variables named val1 and val2. Write your program to determine the smaller,
* larger, sum, difference, product, and ratio of these values and report them to the
* user.
*/
#include "../std_lib_facilities.h"

int main()
{
  int val1, val2;

  cout << "Enter two numbers separeted by space: " << endl;
  cin >> val1 >> val2;

  if (val1 < val2)
  {
    cout << "Smaller: " << val1 << endl;
    cout << "Larger: " << val2 << endl;
  } else {
    cout << "Smaller: " << val2 << endl;
    cout << "Larger: " << val1 << endl;
  }
  cout << "Sum: " << val1 + val2 << endl;
  cout << "Difference: " << val1 - val2 << endl;
  cout << "Product: " << val1 * val2 << endl;
  cout << "Ratio: " << val1 / val2 << endl;

  return 0;
}
