/**
* Write a program that prompts the user to enter three integer values, and then
* outputs the values in numerical sequence separeted by commas. So, if the user
* enters the values 10 4 6, the output should be 4, 6, 10. If two values are the
* same, the should just be ordered together. So the input 4 5 4. sould give 4, 4 5.
*/
#include "../std_lib_facilities.h"

int main()
{
  int n1, n2, n3;
  cout << "Type 3 numbers separeted by blank space: ";
  cin >> n1;
  cin >> n2;
  cin >> n3;
  cout << "Okay... I will output in numerical order." << endl;

  if (n1 <= n2 && n1 <= n3) {
    if (n2 < n3)
    {
      cout << n1 << ", " << n2 << ", " << n3 << endl;
    } else
    {
      cout << n1 << ", " << n3 << ", " << n2 << endl;
    }
  } else if (n2 <= n1 && n2 <= n3)
  {
    if (n3 < n1)
    {
      cout << n2 << ", " << n3 << ", " << n1 << endl;
    } else
    {
      cout << n2 << ", " << n1 << ", " << n3 << endl;
    }
  } else if (n3 <= n1 && n3 <= n2)
  {
    if (n2 < n1)
    {
      cout << n3 << ", " << n2 << ", " << n1 << endl;
    } else
    {
      cout << n3 << ", " << n1 << ", " << n2 << endl;
    }
  }


  return 0;
}
