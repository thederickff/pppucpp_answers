/*
  1. Start a program called Test_output.cpp. Declare an integer birth_year and
     assign it the year you were born.
  2. Output your birth_year in decimal, hexadecimal, and octal form.
  3. Label each value with the name of the base used.
  4. Did you line up your output in columns using the tab character? If not,
     do it.
  5. Now output your age.
*/
#include "../std_lib_facilities.h"

int main()
{
  int birth_year = 2001;

  cout << "Decimal: " << birth_year << '\t' <<
  hex << "Hexadecimal: " << birth_year << '\t' <<
  oct << "Octal: " << birth_year << '\n';
  cout << "Age: " << (2018 - birth_year) << '\n';
  return 0;
}
