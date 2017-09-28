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
