/*
  Write a program that produces the sum of all whitespace-separated integers in
  a text file. For example, bears: 17 elephants 9 end should output 26.
*/
#include "std_lib_facilities.h"

bool whitespace(char ch)
{
  return (ch == ' ' || ch == '\t' || ch == '\n');
}

bool digit(char ch)
{
  switch (ch) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      return true;
    default:
      return false;
  }
}

int main()
{
  try {
    cout << "Please enter an input file name: ";
    string name;
    cin >> name;
    ifstream is(name.c_str());
    if (!is) error("Bad input file name ", name);

    string s;
    int n;
    int sum = 0;
    int count = 0;  // I just want to know how many integers I found
    char ch;

    while (is >> ch) {  // skips whitespace
      if (digit(ch)) {  // we found an integer, but what about 12.7 and 12F?
        is.putback(ch); // put the digit back so that we can read the whole integer
        if (is >> n) {
          if (is.get(ch) && whitespace(ch)) { // is the character following the integer a whitespace?
            ++count;
            sum += n;
          } else {
            is.putback(ch);  // in case the next character is a whitespace (example: foo 12F bar)
            is >> s;        // read the rest of the string
          }
        } else {
          error("impossible");  // error message "just in case"
        }

      } else {
          is.putback(ch);
          is >> s;            // read the string as a string
      }

    }

    cout << "integer count: " << count << " sum: " << sum << '\n';

    keep_window_open("~");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
    keep_window_open("~");
  } catch (...) {
    cout << "exiting\n";
    keep_window_open("~");
  }

  return 0;
}
