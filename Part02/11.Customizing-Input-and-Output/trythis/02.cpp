/*
  Complete the code fragment above to make it into a program. Try the suggested
  input; then type in
  1234 1234 1234 1234
  Explain the results. Try other inputs to see what happens.
*/
#include "../std_lib_facilities.h"

int main()
{
  int a, b, c, d;

  cin.unsetf(ios::dec); // don't assume decimal (so that 0x can mean hex)
  cin.unsetf(ios::oct); // don't assume octal (so that 12 can mean twelve)
  cin.unsetf(ios::hex); // don't assume hexadecimal (so that 12 can mean twelve)
  //cin >> a >> hex >> b >> oct >> c >> d;
  cin >> a >> b >> c >> d;
  cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

  return 0;
}
