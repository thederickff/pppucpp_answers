/*
  Output your birth year in decimal, hexadecimal, and octal form. Label each
  value. Line up your output in columns using the tab character. Now output
  your age.

  Integer output manipulations
  oct           use base-8 (octal) notation
  dec           use base-10 (decimal) notation
  hex           use base-16 (hexadecimal) notation
  showbase      prefix 0 for octal and 0x for hexadecimal
  noshowbase    don't use prefixes
*/
#include "../std_lib_facilities.h"

int main()
{
  int birth_year = 2001;

  cout << "Birth Year!!\n";
  cout << birth_year << "\t(decimal)\n";
  cout << hex << birth_year << "\t(hexadecimal)\n";
  cout << oct << birth_year << "\t(octal)\n";
  cout << showbase << "Show bases!!\n";
  cout << "Age: " << dec << (2018 - birth_year) << '\n';
  cout << birth_year << "\t(decimal)\n";
  cout << hex << birth_year << "\t(hexadecimal)\n";
  cout << oct << birth_year << "\t(octal)\n";
  cout << "Age: " << dec << (2018 - birth_year) << '\n';

  cout << "Integer literal of 0x7d1: " << 0x7d1 << '\n';
  cout << "Integer literal of 03721: " << 03721 << '\n';
  cout << "No showbase " << noshowbase << oct << birth_year << '\n';
  return 0;
}
