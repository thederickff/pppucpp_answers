/*
  Write a function maxv() that returns the largest element of a vector argument
  and also computes the mean and the median. Do not use global variables. Either
  return a struct containing the results or pass them back through reference
  arguments. Which of the two ways of returning several result values do you
  prefer and why?
*/
#include "../std_lib_facilities.h"

double maxv(vector<double>& array, double& mean, double& median)
{
  sort(array);
  int mostRepeated = 0;
  for (int i = 0; i < array.size(); ++i) {
      int repeats = 0;
      for (int j = 0; j < i; ++j) {
          if (array[i] == array[j]) {
            repeats++;
          }
      }


      if (mostRepeated < repeats) {
          mostRepeated = repeats;
          mean = array[i];
      }
  }

  median = array[array.size() / 2];

  return array[array.size() - 1];
}

int main()
{
  vector<double> array = {2.3, 4.5, 7.34, 2.23, 2.3, 7.1, 1.2, 0.8, 0.938, 4.5, 4.5};
  double mean, median, largest;

  largest = maxv(array, mean, median);

  for (double a : array) {
    cout << a << "\t";
  }

  cout << "\n###############################################################\n";
  cout << "Mean: " << mean << '\n';
  cout << "Median: " << median << '\n';
  cout << "Largest: " << largest << '\n';

  return 0;
}
