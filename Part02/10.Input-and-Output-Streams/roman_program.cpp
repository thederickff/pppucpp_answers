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
  Roman_int() {}
  Roman_int(string roman);
  int as_int();

  void add(char ch) { characters.push_back(ch); }
  vector<char> getCharacters() const { return characters; }
private:
  vector<char> characters;
  int number;
};
string int_to_roman(int number);

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
Roman_int::Roman_int(string roman)
{
  characters.reserve(roman.size());
  for (int i = 0; i < roman.size(); ++i) {
    characters.push_back(roman[i]);
  }
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

Roman_int operator+(Roman_int& a, Roman_int& b)
{
  int sum = a.as_int() + b.as_int();
  return Roman_int(int_to_roman(sum));
}

Roman_int operator-(Roman_int& a, Roman_int& b)
{
  int sum = a.as_int() - b.as_int();
  return Roman_int(int_to_roman(sum));
}
Roman_int operator*(Roman_int& a, Roman_int& b)
{
  int sum = a.as_int() * b.as_int();
  return Roman_int(int_to_roman(sum));
}
Roman_int operator/(Roman_int& a, Roman_int& b)
{
  int sum = a.as_int() / b.as_int();
  return Roman_int(int_to_roman(sum));
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


vector<string> romans_tbl = {
  "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"
};
vector<int> number_tbl { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

string int_to_roman(int number)
{
  string roman = "";
  int times = 0;
  for (int i = romans_tbl.size()-1; i > 0; --i) {
    times = number / number_tbl[i];
    number %= number_tbl[i];
    while (times > 0) {
      roman += romans_tbl[i];
      times--;
    }
  }

  return roman;
}

int main()
{

  Roman_int r, r2, result;
  char operator_sign;
  cin >> r;
  cin >> operator_sign;
  cin >> r2;
  switch (operator_sign) {
    case '+':
      result = r + r2;
      break;
    case '-':
      result = r - r2;
      break;
    case '*':
      result = r * r2;
      break;
    case '/':
      result = r / r2;
      break;
    default:
      error("Unknown operator sign");
  }

  cout << "= " << result << "\n";

  return 0;
}
