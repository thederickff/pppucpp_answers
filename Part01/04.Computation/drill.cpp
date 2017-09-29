#include "../std_lib_facilities.h"

// Global
double smallest = 10000;
double largest = -10000;


void checkUnit(string unit);
void update(double n);

int main()
{
  double number;
  double numbersEntered = 0;
  double totalMeters = 0;
  vector<double> meters;
  // cm, m, ft, in
  string unit;

  string guess = "Enter a number and a unit (such as m, cm, ft or in), Type | to end.";
  cout << guess << endl;

  while(cin >> number) {
    cin >> unit;
    // CheckUnit
    checkUnit(unit);
    cout << "The number entered " << number << unit << " is equivalent to:" << endl;
    // Converts all the unit typed to meters if needed
    // 1m = 100cm, 1in = 2.54cm, 1ft = 12in
    if(unit == "cm")
      number = number / 100;
    else if(unit == "in")
      number = (number * 2.54) / 100;
    else if(unit == "ft")
      number = ((number * 12) * 2.54) / 100;

    // Update the smallest, largest number
    update(number);
    // Add the number in meters
    meters.push_back(number);

    numbersEntered++;
    cout << guess << endl;
  }

  cout << "The smallest number entered: " << smallest << endl;
  cout << "The largest number entered: " << largest << endl;
  cout << "Numbers entered: " << numbersEntered << endl;

  // sort
  sort(meters);
  for (double n : meters) {
    totalMeters += n;
    cout << n << "m" << endl;
  }
  cout << "Sum of all the meters: " << totalMeters << endl;
  return 0;
}

void checkUnit(string unit)
{
  if (unit != "m" && unit != "cm" & unit != "in" && unit != "ft") {
    simple_error("Unknown unit type entered");
  }
}

void update(double n) {
  if (n < smallest) {
    smallest = n;
    cout << "The smallest so far " << endl;
  }

  if (n > largest) {
    largest = n;
    cout << "The largest so far " << endl;
  }
}
