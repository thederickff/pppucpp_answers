/*
  Design and implement a rational number class, Rational. A rational number has
  two parts: a numerator and a denominator, for example, 5/6 (five-sixths, also
  known as approximately .83333). Look up the definition if you need to. Provide
  assignment, addition, subtraction, multiplication, division, and equality
  operators. Also, provide a conversion to double. Why would people want to use
  a Rational class?

  To represent a floating-point number more clearly
*/
#include "../std_lib_facilities.h"

class Rational
{
public:
  class InvalidRational {};
  Rational() : enumerator(0), denominator(0) { }
  Rational(const Rational& other)
      : enumerator(other.getEnumerator()), denominator(other.getDenominator()) { }
  Rational(const char* value) : enumerator(0), denominator(0)
  {
    string e, d, svalue = string(value);
    bool part2 = false;

    for (int i = 0; i < svalue.size(); ++i) {
      if (value[i] == '/') {
        part2 = true;
        continue;
      }
      if (part2) {
        d += value[i];
      } else {
        e += value[i];
      }
    }
    enumerator = stoi(e);
    denominator = stoi(d);

    if (svalue.size() < 3 || denominator == 0) throw InvalidRational();
}

int getEnumerator() const { return enumerator; }
int getDenominator() const { return denominator; }
double getValue() const { return ((double)enumerator) / ((double) denominator); }
private:
  int enumerator;
  int denominator;
};
ostream& operator<<(ostream& os, const Rational& rational);
Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
bool operator==(const Rational& a, const Rational& b);
bool operator!=(const Rational& a, const Rational& b);
string common_denominator(const Rational& a, const Rational& b);

ostream& operator<<(ostream& os, const Rational& rational)
{
  os << '(' << rational.getEnumerator() << '/' << rational.getDenominator() << " or " << rational.getValue() << ')';
  return os;
}

Rational operator+(const Rational& a, const Rational& b)
{
  int enum_a = a.getEnumerator() * b.getDenominator();
  int enum_b = b.getEnumerator() * a.getDenominator();

  string result = to_string(enum_a + enum_b) + "/" + common_denominator(a, b);
  return Rational(result.c_str());
}
Rational operator-(const Rational& a, const Rational& b)
{
  int enum_a = a.getEnumerator() * b.getDenominator();
  int enum_b = b.getEnumerator() * a.getDenominator();

  string result = to_string(enum_a - enum_b) + "/" + common_denominator(a, b);
  return Rational(result.c_str());
}

Rational operator*(const Rational& a, const Rational& b)
{
  int enumerator = a.getEnumerator() * b.getEnumerator();
  int denominator = a.getDenominator() * b.getDenominator();

  string result = to_string(enumerator) + "/" + to_string(denominator);
  return Rational(result.c_str());
}
Rational operator/(const Rational& a, const Rational& b)
{
  int enumerator = a.getEnumerator() * b.getDenominator();
  int denominator = a.getDenominator() * b.getEnumerator();

  string result = to_string(enumerator) + "/" + to_string(denominator);
  return Rational(result.c_str());
}
bool operator==(const Rational& a, const Rational& b)
{
  return a.getEnumerator() == b.getEnumerator() && a.getDenominator() == b.getDenominator();
}
bool operator!=(const Rational& a, const Rational& b)
{
  return !(a == b);
}

string common_denominator(const Rational& a, const Rational& b)
{
  return to_string(a.getDenominator() * b.getDenominator());
}

int main()
{
  Rational num1 = "5/2";
  Rational num2 = "5/6";
  Rational result = num1 + num2;

  cout << "Sum: " << result << '\n';
  result = num1 - num2;
  cout << "Difference: " << result << '\n';
  result = num1 * num2;
  cout << "Module: " << result << '\n';
  result = num1 / num2;
  cout << "Division: " << result << '\n';
  Rational num3 = num1;
  string theSame = num1 == num3? string("yes") : string("no");
  cout << "Num1: " << num1 << '\n';
  cout << "Num3: " << num3 << ", is num1 equal to num3? " << theSame << '\n';
  theSame = num2 == num3? string("yes") : string("no");
  cout << "Num2: " << num2 << ", is num2 equal to num3? " << theSame << '\n';
  return 0;
}
