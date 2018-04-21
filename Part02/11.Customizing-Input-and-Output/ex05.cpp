/*
  Write a program that reads strings  and for each  string outputs the character
  classification of each character,  as defined by the character  classification
  functions  presented  in  §11.6.  Note  that  a  character  can  have  several
  classifications (e.g, x is both a letter and an alphanumeric).
*/
#include "std_lib_facilities.h"

int main()
{
  vector<string> strs;
  cout << "Input a few strings use 'end' word to end input\n";
  for (string str; cin >> str; ) {
    if (str == "end") break;
    strs.push_back(str);
  }

  for (string& str : strs) {
    cout << "---------------\nString: " << str << "\n---------------\n";
    for (char& ch : str) {
      cout << ch << ":\t";

      if (isspace(ch)) { // whitespace (' ', '\t', 'n')
        cout << "whitespace\t";
      }
      if (isalpha(ch)) { // letter ('a' .. 'z', 'A' .. 'Z') (note: not '_')
        cout << "letter\t";
      }
      if (isdigit(ch)) { // decimal digit ('0' .. '9')
        cout << "decimal\t";
      }
      if (isxdigit(ch)) { // hexadecimal digit (decimal digit or 'a' .. 'f', 'A' .. 'F')
        cout << "hexadecimal\t";
      }
      if (isupper(ch)) { // uppercase letter ('A' .. 'Z')
        cout << "uppercase\t";
      }
      if (islower(ch)) { // lowercase letter ('a' .. 'z')
        cout << "lowercase\t";
      }
      if (isalnum(ch)) { // letter or decimal digit
        cout << "alnum\t";
      }
      if (iscntrl(ch)) { // control character (ASCII 0..31 and 127)
        cout << "control\t";
      }
      if (ispunct(ch)) { // not a letter, digit, or whitespace, or invisible control character
        cout << "is punct\t";
      }
      if (isprint(ch)) { // printable (ASCII ' '..'~')
        cout << "printable\t";
      }
      if (isgraph(ch)) { // is isalpha(ch) or isdigit(ch) or ispunct(ch) (note: not space)
        cout << "a graph\t";
      }

      cout << '\n';
    }
  }

  return 0;
}
