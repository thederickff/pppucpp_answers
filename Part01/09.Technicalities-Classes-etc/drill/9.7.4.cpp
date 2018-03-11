#include "../../std_lib_facilities.h"

enum class Month
{
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
class Date
{
public:
  class Invalid {};
  Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd)
  {
    if (!is_valid()) throw Invalid();
  }

  Month month() const { return m; }
  int day() const { return d; }
  int year() const { return y; }

  void add_day(int n) { d += n; }
  void add_month(int n) { m = Month(int(m) + n); }
  void add_year(int n) { y += n; }
  bool is_valid()
  {
    if (d <= 0 || d >= 32) return false;
    if (int(m) <= 0 || int(m) >= 13) return false;
    return true;
  }

private:
  int y;
  Month m;
  int d;
};


ostream& operator<<(ostream& os, const Date& date)
{
  return os << '(' << date.year()  << ',' << int(date.month()) << ',' << date.day() << ')';
}


int main()
{
  try {
    Date today {1978, Month::jun, 25};
    Date tomorrow {today};
    tomorrow.add_day(2);
    cout << today << '\n';
    cout << tomorrow << '\n';

    Date invalid {2004, Month::aug, -5};
    cout << invalid << '\n';
    invalid.add_day(1);
    cout << invalid << '\n';
    invalid.add_month(3);
    cout << invalid << '\n';
  } catch (Date::Invalid& e) {
    cerr << "Invalid date!\n";
  }

  return 0;
}
