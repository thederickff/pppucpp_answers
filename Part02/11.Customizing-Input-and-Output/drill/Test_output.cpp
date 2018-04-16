/*
  1. Start a program called Test_output.cpp. Declare an integer birth_year and
  assign it the year you were born.
  2. Output your birth_year in decimal, hexadecimal, and octal form.
*/
#include "../std_lib_facilities.h"

int main()
{
  int birth_year = 2001;

  cout << birth_year << ' ' << hex << birth_year << ' ' << oct << birth_year << '\n';

  return 0;
}
