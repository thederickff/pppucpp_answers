/*
  Implement leapyear() from §9.8.
*/
#include "../std_lib_facilities.h"
#include "Chrono.h"

int main()
{
  Chrono::Date before {2016, Chrono::Month::mar, 24};
  Chrono::Date then {2017, Chrono::Month::mar, 24};
  Chrono::Date now {2018, Chrono::Month::mar, 24};
  Chrono::Date soon {2019, Chrono::Month::mar, 24};
  Chrono::Date after {2020, Chrono::Month::mar, 24};


  if (Chrono::leapyear(before.year())) {
    cout << "Before(2016) is a leapyear!\n";
  } else {
    cout << "Before(2016) isn't a leapyear!\n";
  }

  if (Chrono::leapyear(then.year())) {
    cout << "Then(2017) is a leapyear!\n";
  } else {
    cout << "Then(2017) isn't a leapyear!\n";
  }

  if (Chrono::leapyear(now.year())) {
    cout << "Now(2018) is a leapyear!\n";
  } else {
    cout << "Now(2018) isn't a leapyear!\n";
  }

  if (Chrono::leapyear(soon.year())) {
    cout << "Soon(2019) is a leapyear!\n";
  } else {
    cout << "Soon(2019) isn't a leapyear!\n";
  }

  if (Chrono::leapyear(after.year())) {
    cout << "After(2020) is a leapyear!\n";
  } else {
    cout << "After(2020) isn't a leapyear!\n";
  }

  return 0;
}
