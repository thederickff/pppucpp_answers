/*
  Write a function maxv() that returns the largest element of a vector argument.
*/
#include "../std_lib_facilities.h"

double maxv(vector<double> array)
{
  sort(array);

  return array[array.size() - 1];
}

int main()
{
  vector<double> array = {2.3, 4.5, 7.34, 8.23, 2.3, 7.1, 1.2, 0.8, 0.938, 4.5, 4.5};
  double largest = maxv(array);

  for (double a : array) {
    cout << a << "\t";
  }

  cout << "\n###############################################################\n";
  cout << "Largest: " << largest << '\n';

  return 0;
}
