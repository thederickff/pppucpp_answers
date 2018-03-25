/*
  Design and implement a set of useful helper functions for the Date class with
  functions such as next_workday() (assume that any day that is not a Saturday
  or a Sunday is a workday) and week_of_year() (assume that week 1 is the week
  with january 1 in it and that the first day of week is a Sunday).
*/
#include "../std_lib_facilities.h"
#include "Chrono.h"

int main()
{
  Chrono::Date date {1988, Chrono::Month::sep, 30};
  string days[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
  Chrono::Day day = Chrono::day_of_week_on_date(date);
  cout << "Day of the week in " << date << " is " << days[int(day)] << '\n';

  cout << "Next workday of " << date << " is ";
  Chrono::next_workday(date);
  cout << date << '\n';
  return 0;
}
