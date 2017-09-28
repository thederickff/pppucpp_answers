/**
* Do exercise 6, but with three strings values. So, if the user enters the values
* Steinbeck, Hemingway, Fitzgerald, the output should be Fitzgerald, Hemingway, Steinbeck.
*/
#include "../std_lib_facilities.h"

int main()
{
  string s1, s2, s3;
  cout << "Type 3 words separeted by blank space: ";
  cin >> s1;
  cin >> s2;
  cin >> s3;
  cout << "Okay... I will output in alphabet order." << endl;

  if (s1 <= s2 && s1 <= s3) {
    if (s2 < s3)
    {
      cout << s1 << ", " << s2 << ", " << s3 << endl;
    } else
    {
      cout << s1 << ", " << s3 << ", " << s2 << endl;
    }
  } else if (s2 <= s1 && s2 <= s3)
  {
    if (s3 < s1)
    {
      cout << s2 << ", " << s3 << ", " << s1 << endl;
    } else
    {
      cout << s2 << ", " << s1 << ", " << s3 << endl;
    }
  } else if (s3 <= s1 && s3 <= s2)
  {
    if (s2 < s1)
    {
      cout << s3 << ", " << s2 << ", " << s1 << endl;
    } else
    {
      cout << s3 << ", " << s1 << ", " << s2 << endl;
    }
  }

  return 0;
}
