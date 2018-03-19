#include "Chrono.h"

namespace Chrono {

  Date::Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd)
  {
    if (!is_valid()) throw Invalid();
  }

  const Date& default_date()
  {
    static Date dd {2001, Month::jan, 1}; // start of 21st century
    return dd;
  }
  Date::Date()
      : y(default_date().year()), m(default_date().month()), d(default_date().day())
  {

  }

  bool Date::is_valid()
  {
    if (d <= 0 || d >= 32) return false;
    if (int(m) <= 0 || int(m) >= 13) return false;
    return true;
  }

  ostream& operator<<(ostream& os, const Date& date)
  {
    return os << '(' << date.year()  << ',' << int(date.month()) << ',' << date.day() << ')';
  }

}
