/* Converts from yen, euro, pounds, yuan or Norwegian Krone to dollar
* The suffix 'y', 'e', 'p', 'u', 'k' indicates the unit of the input
* any other suffix is an error
* Data: 9/25/17
*/
#include "../std_lib_facilities.h"

int main(int argv, char* argc[]) {
  // TRY THIS 01 and 02
  constexpr double yen_per_dollar = 111.61;
  constexpr double euro_per_dollar = 0.84;
  constexpr double pound_per_dollar = 0.74;
  constexpr double yuan_per_dollar = 6.62;
  constexpr double krone_per_dollar = 7.83;

  double currency = 1;

  char unit;

  cout << "Converts from yen, euro, pounds, yuan or krone to dollar." << endl;;
  cout << "Please enter a currency type followed by a unit (y, e, p, u or k):" << endl;
  cin >> currency >> unit;

  switch (unit) {
    case 'y':
      cout << currency << " yens is equals to " << currency/yen_per_dollar << " dollars." << endl;
      break;
    case 'e':
      cout << currency << " euros is equals to " << currency/euro_per_dollar << " dollars." << endl;
      break;
    case 'p':
      cout << currency << " pounds is equals to " << currency/pound_per_dollar << " dollars." << endl;
      break;
    case 'u':
      cout << currency << " yuans is equals to " << currency/yuan_per_dollar << " dollars." << endl;
      break;
    case 'k':
      cout << currency << " kroners is equals to " << currency/krone_per_dollar << " dollars." << endl;
      break;
    default:
      cout << "Sorry, I don't this unit type." << endl;

  }

  return 0;
}
