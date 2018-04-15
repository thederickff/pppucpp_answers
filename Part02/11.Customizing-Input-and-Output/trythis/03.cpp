/*
  Write some code to print the number 1234567.89 three times, first using
  defaultfloat, then fixed, then scientific. Which output form presents the
  user with the most accurate representation? Explain why.

  Fixed presents the most accurate representation, because it shows 1234567.875,
  which is more accurate than 1234567.8 (1.2345678e+06) or 1234570 (1.23457+e06)

  Floating-point formats
  fixed         use fixed-point notation

  scientific    use mantissa and exponent notation; the mantissa is always in
                the [1:10] range; that is, there is a single nonzero digit
                before the decimal point

  defaultfloat  choose fixed or scientific to give the numerically most accurate
                representation, within the precision of defaultfloat.

  Floating-point precision

  defaultfloat    precision is the total number of digits
  scientific      precision is the number of digits after the decimal point
  fixed           precision is the number of digits after the decimal point

  Use the default (defaultfloat format with precision 6) unless there is a
  reason not to. The usual reason not to is "Because we need greater accuracy
  of the output."
*/
#include "../std_lib_facilities.h"

int main()
{
  float number = 1234567.89;

  cout << number << '\t' << fixed << number << '\t' << scientific << number << '\n';
  cout << "--With precision--\n";
  cout << setprecision(8) << number << '\t' << fixed << number << '\t' << scientific << number << '\n';

  return 0;
}
