#include "../std_lib_facilities.h"

int main()
{
  vector<double> temps;

  for (double temp; cin >> temp;) {
    temps.push_back(temp);
  }


  double sum = 0;
  for (int x : temps) sum += x;

  cout << "Average temperature: " << sum/temps.size() << endl;

  sort(temps);
  cout << "Median temperature: " << temps[temps.size()/2] << endl;

  return 0;
}
