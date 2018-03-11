#include "../../std_lib_facilities.h"

class Date {
  int y, m, d;
public:
  Date(int yy, int mm, int dd) : y(yy), m(mm), d(dd)
  {
    if (!is_valid()) cout << '(' << yy << ',' << mm << ',' << dd << "): Invalid Date!\n";
  }

  void add_day(int n) { d += n; }
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }

  bool is_valid()
  {
    if (d <= 0 || d >= 32) return false;
    if (m <= 0 || m >= 13) return false;
    return true;
  }

};

ostream& operator<<(ostream& os, Date& date)
{
  return os << '(' << date.year()  << ',' << date.month() << ',' << date.day() << ')';
}

int main()
{
  Date today {1978, 6, 25};
  Date tomorrow {today};
  tomorrow.add_day(2);
  Date invalid {2004, 13, -5};

  cout << today << '\n';
  cout << tomorrow << '\n';
  cout << invalid << '\n';
  invalid.add_day(1);
  cout << invalid << '\n';


  return 0;
}
