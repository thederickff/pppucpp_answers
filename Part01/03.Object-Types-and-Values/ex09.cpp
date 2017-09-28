/**
* Write a program that converts spelled-out numbers such as "zero" and "two" into
* Such as 0 and 2. Do it for the values 1, 2, 3, and 4 and write out not a number
* I know if the user enters something that doesn't correspond, such as stupid comuter!.
*/
#include "../std_lib_facilities.h"

int main()
{
  // Hold spelled-out numbers ex: one, two, three or four
  string number;
  int n;
  cout << "Type a spelled-out number between 0 and 5: " << endl;
  cin >> number;
  if (number == "one")
    n = 1;
  else if (number == "two")
    n = 2;
  else if (number == "three")
    n = 3;
  else if (number == "four")
    n = 4;
  else
    n = 0;

  if (n == 0)
    cout << "Not a number I know." << endl;
  else
  cout << "The spelled-out number " << number << " is " << n << endl;

  return 0;
}
