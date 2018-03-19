#include "../std_lib_facilities.h"

namespace Chrono {
  enum class Month
  {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };
  class Date
  {
  public:
    class Invalid {};
    Date(int yy, Month mm, int dd);
    Date();

    Month month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }

    void add_day(int n) { d += n; }
    void add_month(int n) { m = Month(int(m) + n); }
    void add_year(int n) { y += n; }
    bool is_valid();

  private:
    int y;
    Month m;
    int d;
  };

  ostream& operator<<(ostream& os, const Date& date);
}
