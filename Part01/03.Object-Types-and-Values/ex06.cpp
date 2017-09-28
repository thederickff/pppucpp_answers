#include "../std_lib_facilities.h"

int main()
{
  int n1, n2, n3;
  cout << "Type 3 numbers separeted by blank space: ";
  cin >> n1;
  cin >> n2;
  cin >> n3;
  cout << "Okay... I will output in numerical order." << endl;

  if (n1 < n2 && n1 < n3) {
    if (n2 < n3)
    {
      cout << n1 << ", " << n2 << ", " << n3 << endl;
    } else
    {
      cout << n1 << ", " << n3 << ", " << n2 << endl;
    }
  } else if (n2 < n1 && n2 < n3)
  {
    if (n3 < n1)
    {
      cout << n2 << ", " << n3 << ", " << n1 << endl;
    } else
    {
      cout << n2 << ", " << n1 << ", " << n3 << endl;
    }
  } else if (n3 < n1 && n3 < n2)
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
