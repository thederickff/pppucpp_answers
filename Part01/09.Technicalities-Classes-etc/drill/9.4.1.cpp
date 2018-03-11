#include "../../std_lib_facilities.h"

class Invalid {};
struct Date {
  int y;  // year
  int m;  // month in year
  int d;  // day of month
};

bool is_valid(const Date& date)
{
  if (date.d <= 0 || date.d > 31) return false;
  if (date.m <= 0 || date.m > 12) return false;
  return true;
}

void add_day(Date& date)
{
  date.d += 1;
}

ostream& operator<<(ostream& os, const Date& date)
{
  return os << '(' << date.y << ',' << date.m << ',' << date.d << ')';
}

int main()
{
  try {
    Date today;
    today.y = 1978;
    today.m = 6;
    today.d = 25;

    Date tomorrow = today;
    add_day(tomorrow);
    Date invalid;
    invalid.y = 2004;
    invalid.m = 13;
    invalid.d = -5;

    cout << today << '\n';
    cout << tomorrow << '\n';
    cout << invalid << '\n';
    add_day(invalid);
    cout << invalid << '\n';

    if (!is_valid(today)) throw Invalid();
    if (!is_valid(tomorrow)) throw Invalid();
    if (!is_valid(invalid)) throw Invalid();
  } catch (exception& e) {
    cerr << "An error occurred: " << e.what() << '\n';
  }

  return 0;
}
