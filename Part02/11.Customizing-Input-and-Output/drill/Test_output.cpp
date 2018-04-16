/*
  1. Start a program called Test_output.cpp. Declare an integer birth_year and
     assign it the year you were born.
  2. Output your birth_year in decimal, hexadecimal, and octal form.
  3. Label each value with the name of the base used.
  4. Did you line up your output in columns using the tab character? If not,
     do it.
  5. Now output your age.
  6. Was there a problem? What happened? Fix your output to decimal.
  7. Go back to 2 and cause your output to show the base for each output.
  8. Try reading as octal, hexadecimal, etc.:
       cin >> a >> oct >> b >> hex >> c >> d;
       cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
     Run this code with the input:
       1234 1234 1234 1234
     Explain the results.
*/
#include "../std_lib_facilities.h"

int main()
{
  int birth_year = 2001, a, b, c, d;

  cout << showbase << "Decimal: " << birth_year << '\t' <<
  hex << "Hexadecimal: " << birth_year << '\t' <<
  oct << "Octal: " << birth_year << '\n';
  cout << "Age: " << dec << (2018 - birth_year) << '\n';

  cin >> a >> oct >> b >> hex >> c >> d;
  /*
    Input:
      1234 1234 1234 1234
    Ouputs:
      1234 668 4660 4660

    To output the correct values 1234 the input should be:
      1234 01234 4d2 4d2
      
    668 in decimal is the equivalent to 1234 in octal
    4660 in decimal is the equilent to 1234 in hexadecimal
  */
  cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';


  return 0;
}
