/**
* Modify the previous program to ask the user to enter floating-point values and
* and store them in double variables.
*/
#include "../std_lib_facilities.h"

int main()
{

  double val1, val2;

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
