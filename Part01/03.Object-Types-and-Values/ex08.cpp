/**
* Write a program to test an integer value to determinne if it is odd or even.
* As always, make sure your output is clear and complete. In other words, don't
* just use yes or no. Your ouput should stand alone, like the value 4 is an even
* number.
*/
#include "../std_lib_facilities.h"

int main()
{
  int number;
  string type;
  cout << "Type a number: " << endl;
  cin >> number;
  if (number % 2 == 0)
  {
    type = "even";
  } else
  {
    type = "odd";
  }

  cout << "The number " << number << " is " << type << endl;
  return 0;
}
