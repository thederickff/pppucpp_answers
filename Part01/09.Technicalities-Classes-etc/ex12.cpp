/*
  Change the representation of a Date to be the number of days since January 1,
  1970 (known as day 0), represented as a long int, and re-implement the
  funtions from §9.8. Be sure to reject dates outside the range we can represent
  that way (feel free to reject days before day 0, i.e., no negative days).
*/
#include "../std_lib_facilities.h"
#include "Chrono2.h"

int main()
{
  int days = Chrono::days_since(2001, Chrono::Month::feb, 28);
  cout << "Days: " << days << '\n';
  Chrono::Date date(days);
  cout << date << '\n';
  Chrono::Date provided;
  cout << "Type a date by yourself in this format include the parenthensis: (yy, mm, dd)\n";
  cin >> provided;

  cout << "> " << provided << '\n';

  return 0;
}
