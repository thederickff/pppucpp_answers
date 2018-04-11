/*
  Define a Roman_int class for holding Roman numerals (as ints) with a << and >>.
  Provide Roman_int with an as_int() member that returns the int value, so that if
  r is a Roman_int, we can write cout << "Roman" << r << " equals " << r.as_int()
  << '\n';
  ============
  | I -    1 |
  | V -    5 |
  | X -   10 |
  | L -   50 |
  | C -  100 |
  | D -  500 |
  | M - 1000 |
  ============
*/
#include "std_lib_facilities.h"

class Roman_int {
public:
  int as_int();

  void add(char ch) { characters.push_back(ch); }
  vector<char> getCharacters() const { return characters; }
private:
  vector<char> characters;
  int number;
};

int charValue(char roman_char)
{
  switch (roman_char) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
  }
  return -1;
}

int Roman_int::as_int()
{
  int total = 0;
  for (int i = 0; i < characters.size(); ++i) {
    int value = charValue(characters[i]);
    if ((i+1) != characters.size() && value < charValue(characters[i+1])) {
      total -= value;
    } else {
      total += value;
    }
  }

  return total;
}

istream& operator>>(istream& is, Roman_int& r)
{
  for (char ch; is >> ch; ) {
    if (ch == ';') break;
    if (charValue(ch) == -1) error("Unreconized roman number");
    r.add(ch);
  }

  if (!is) {
    error("Failed to read Roman_int");
  }

  return is;
}
ostream& operator<<(ostream& os, const Roman_int& r)
{
  for (char ch : r.getCharacters()) {
    os << ch;
  }
  return os;
}

int main()
{

  while(true) {
    Roman_int r;
    cin >> r;
    cout << "Roman " << r << " equals " << r.as_int() << '\n';
  }

  return 0;
}
