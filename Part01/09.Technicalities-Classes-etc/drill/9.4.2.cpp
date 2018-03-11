#include "../../std_lib_facilities.h"

struct Date {
  int y;  // year
  int m;  // month in year
  int d;  // day of month

  Date(int yy, int mm, int dd) : y(yy), m(mm), d(dd)
  {
        if(!is_valid()) cout << '(' << yy << ',' << mm << ',' << dd<< "): Invalid!\n";
  }
  void add_day(int n) { d += n; }

  bool is_valid()
  {
    if (d <= 0 || d > 31) return false;
    if (m <= 0 || m > 12) return false;
    return true;
  }
};


ostream& operator<<(ostream& os, const Date& date)
{
  return os << '(' << date.y << ',' << date.m << ',' << date.d << ')';
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
