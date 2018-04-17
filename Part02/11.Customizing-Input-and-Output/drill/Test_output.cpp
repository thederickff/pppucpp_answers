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
  9. Write some code to print the number 1234567.89 three times, first using the
     defaultfloat, then fixed, then scientific forms. Which output form presents
     the user with the most accurate representation? Explain why.
 10. Make a simple table including last name, first name, telephone number, and
     email address for yourself and at least five of your friends. Experiment
     with different field widths until your are sastified that the table is well
     presented.
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

  cout << "\n-- Drill 09 --\n";
  float number = 1234567.89;

  /*
    Output:
      1.23457e+06   1234567.875000    1.234568e+06
    The most accurate representation form is the fixed (second) form.
    It happens because the precision was set to 6 digits.
  */
  cout << number << '\t' << fixed << number << '\t' << scientific << number << '\n';

  cout << "\n-- Drill 10 --\n";
  cout << "Last name\tFirst Name\tTelephone number\tEmail Address\n";
  cout << "Felix" << setw(10) << "\tDerick" << setw(20) << "\t202-555-0112" << setw(30) << "\temail@example.com\n";
  cout << "Wayne" << setw(10) << "\tJill" << setw(20) << "\t202-555-0191" << setw(25) << "\texample@mail.com\n";
  cout << "Brennan" << setw(10) << "\tJanis" << setw(20) << "\t202-555-0199" << setw(20) << "\tumane@zome.com\n";
  cout << "Alannis" << setw(10) << "\tMerry" << setw(20) << "\t202-555-0140" << setw(30) << "\tleptoac@coldmail.com\n";
  cout << "Grahame" << setw(10) << "\tHailie" << setw(20) << "\t202-555-0177" << setw(30) << "\tuser28527@bmail.com\n";
  cout << "Claire" << setw(10) << "\tCole" << setw(20) << "\t202-555-0142" << setw(30) << "\tuser37826@bmail.com\n";

  return 0;
}
