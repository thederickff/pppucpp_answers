// Chrono.cpp
#include "Chrono2.h"

namespace Chrono {
// Member function definitions

  Date::Date(long int days) : m_Days(days), m_Year(1970),
      m_Day(1), m_Month(Month::jan)
  {
    if (days < 0) throw Invalid();

    for (int i = 0; i < days; ++i)
    {
      add_day(1);
    }
  }

  Date::Date() : m_Days(0), m_Year(1970),
        m_Month(Month::jan), m_Day(1) { } // 1st, January 1970

  void Date::add_day(int n)
  {
    int dim = days_in_month(m_Year, m_Month);
    m_Day += n;
    if (m_Day > dim) {
      m_Day -= dim;
      add_month(1);
    }
  }

  void Date::add_month(int n)
  {
    if (m_Month == Month::dec) {
      m_Month = Month::jan;
      add_year(1);
    } else {
      m_Month = Month(int(m_Month) + 1);
    }
  }

  void Date::add_year(int n)
  {
    m_Year += n;
    if (m_Month == Month::feb && m_Day == 29 && !leapyear(m_Year + n))
    {
      m_Month == Month::mar;
      m_Day = 1;
    }
  }

  // Helper functions:

  int days_since(int year, Month m, int d)
  {
    int days = 0;
    for (int i = 1970; i <= year; i++) {
      int max_month = 12;
      if (i == year) {
        max_month = int(m);
      }
      for (int mm = 1; mm <= max_month; mm++) {
        int dim = days_in_month(i, Month(mm));

        if (i == year && mm == max_month) {
          dim = d;
        }

        days += dim;
      }
    }

    return days-1;
  }

  int days_in_month(int y, Month m)
  {
    int days_in_month = 31;     // most months have 31 days;

    switch (m) {
    case Month::feb:            // the length of Febrary varies
      days_in_month = (leapyear(y))?29:28;
      break;
    case Month::apr: case Month::jun: case Month::sep: case Month::nov:
      days_in_month = 30;       // the rest have 30 days
      break;
    }
    return days_in_month;
  }

  bool leapyear(int y)
  {
    return (y % 4) == 0;
  }

  bool operator==(const Date& a, const Date& b)
  {
    return a.year() == b.year()
          && a.month() == b.month()
          && a.day() == b.day();
  }

  bool operator!=(const Date& a, const Date& b)
  {
    return !(a == b);
  }

  ostream& operator<<(ostream& os, const Date& d)
  {
    return os << '(' << d.year()
              << ", " << int(d.month())
              << ", " << d.day() << ')'
              << " Total days since 1st, January 1970: " << d.days();
  }

  istream& operator>>(istream& is, Date& dd)
  {
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {// ops: format error
      is.clear(ios_base::failbit);                            // set the fail bit
      return is;
    }

    dd = Date(days_since(y, Month(m), d));                   // update dd

    return is;
  }

  Day day_of_week(const Date& d)
  {
    // ...
  }

  Date next_Sunday(const Date& d)
  {
    // ...
  }

  Date next_weekday(const Date& d)
  {
    // ...
  }

  void next_day(Day& day) {
    if (day == Day::saturday) {
      day = Day::sunday;
    } else {
      day = Day(int(day) + 1);
    }
  }

  Day day_of_week_on_date(const Date& d)
  {
    Day day = Day::thursday; // 1st, January of 1970 is a thursday
    int days = 0;
    for (int i = 1970; i <= d.year(); i++) {
      int max_month = 12;
      if (i == d.year()) {
        max_month = int(d.month());
      }
      for (int m = 1; m <= max_month; m++) {
        int daysInMonth = days_in_month(i, Month(m));

        if (i == d.year() && m == max_month) {
          daysInMonth = d.day()-1;
        }

        for (int j = 1; j <= daysInMonth; j++) {
          next_day(day);
        }

        days += daysInMonth;
      }
    }

    return day;
  }

  void next_workday(Date& d)
  {
    Day day_of_week = day_of_week_on_date(d);
    switch (day_of_week) {
      case Day::friday:
        d.add_day(3);
        break;
      case Day::saturday:
        d.add_day(2);
        break;
      default:
        d.add_day(1);
        break;
    }
  }
} // Chrono
