/*
  Refine the Money class by adding a currency (given as a constructor argument).
  Accept a floating-point initializer as long as it can be exactly represented
  as a long int. Don't accept illegal operations. For example, Money*Money
  doesn't make sense, and USD1.23+DKK5.00 makes sense only if you provide a
  conversion table defining the conversion factor between U.S. dollars (USD) and
  Danish kroner (DKK).
*/
#include "../std_lib_facilities.h"

class Money
{
public:
  class InvalidMoney
  {
    public:
      InvalidMoney(double value) : m_Value(value) { }
      void what() { cout <<  "Invalid money input for " << m_Value << '\n'; }
    private:
      double m_Value;
  };
  Money() : m_Cents(0) { }
  Money(double value);
  long int getCents() const { return m_Cents; }
private:
  long int m_Cents;
};
ostream& operator<<(ostream& stream, const Money& money);
istream& operator>>(istream& stream, Money& money);

Money::Money(double value)
{
  if (value < 0) {
    throw InvalidMoney(value);
  }
  double cents = (value - int(value)) * 100;
  m_Cents = int(cents + 0.5) + (int(value) * 100); //  4/5 rounding rule
}

ostream& operator<<(ostream& stream, const Money& money)
{
  double currency = double(money.getCents()) / 100;
  int dollars = int(currency);

  stream << '$' << dollars << '.';
  double cents = (currency - dollars) * 100;
  stream << (cents < 10 ? "0" : "") << cents;
  return stream;
}

istream& operator>>(istream& stream, Money& money)
{
  char ch1;
  double value;
  stream >> ch1 >> value;
  if (!stream) return stream;
  if (ch1 != '$') {
    stream.clear(ios_base::failbit);
    return stream;
  }

  money = value;

  return stream;
}

int main()
{
  try {
    Money food = 3.11;

    cout << food << '\n';
    Money input;
    cout << "Input a money: e.g., $4.23\n";
    cin >> input;
    cout << "Output: " << input << '\n';

  } catch (Money::InvalidMoney& e) {
    e.what();
  }

  return 0;
}
