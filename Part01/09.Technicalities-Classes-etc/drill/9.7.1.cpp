#include "../../std_lib_facilities.h"

enum class Month
{
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
class Date
{
public:
  Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd)
  {
    if (!is_valid()) cout << '(' << yy << ',' << int(mm) << ',' << dd << "): Invalid Date!\n";
  }

  void add_day(int n) { d += n; }
  Month month() { return m; }
  int day() { return d; }
  int year() { return y; }

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


ostream& operator<<(ostream& os, Date& date)
{
  return os << '(' << date.year()  << ',' << int(date.month()) << ',' << date.day() << ')';
}


int main()
{
  Date today {1978, Month::jun, 25};
  Date tomorrow {today};
  tomorrow.add_day(2);
  Date invalid {2004, Month(13), -5};

  cout << today << '\n';
  cout << tomorrow << '\n';
  cout << invalid << '\n';
  invalid.add_day(1);
  cout << invalid << '\n';


  return 0;
}
