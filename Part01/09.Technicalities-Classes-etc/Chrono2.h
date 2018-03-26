#include "../std_lib_facilities.h"
// file Chrono.h
namespace Chrono {
  enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };

  class Date {
  public:
    class Invalid { };  // to throw as exception

    Date(long int days);     // check for valid date and initialize
    Date();             // default constructor

    // nonmodifying operations:
    long int days() const { return m_Days; }
    int year() const { return m_Year; }
    Month month() const { return m_Month; }
    int day() const { return m_Day; }
    // modifying operations:
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
  private:
    long int m_Days;
    int m_Year;
    Month m_Month;
    int m_Day;
  };

  int days_since(int year, Month, int d);
  int days_in_month(int y, Month m);
  bool leapyear(int y);   // true if y is a leap year

  bool operator==(const Date& a, const Date& b);
  bool operator!=(const Date& a, const Date& b);

  ostream& operator<<(ostream& os, const Date& d);

  istream& operator>>(istream& is, Date& dd);

  enum class Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
  };

  void next_day(Day& day);
  Day day_of_week_on_date(const Date& d);
  void next_workday(Date& d);

}                     // Chrono
