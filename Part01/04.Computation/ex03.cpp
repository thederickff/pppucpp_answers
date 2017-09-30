#include "../std_lib_facilities.h"

int main()
{

  vector<double> cityDistance;
  double sum = 0;
  double smallestDistance =  10000000;
  double greatestDistance = -10000000;
  double meanDistance;

  cout << "Type as many distances as possible of two cities along a given route:" << endl;
  for (double cd; cin >> cd;) {
    cityDistance.push_back(cd);
  }

  for (int i = 0; i < cityDistance.size(); i++) {
    cout << "City: " << cityDistance[i] << endl;
    sum += cityDistance[i];
    // Get the smallest and the greatest distance
    if (cityDistance[i] < smallestDistance)
      smallestDistance = cityDistance[i];
    if (cityDistance[i] > greatestDistance)
      greatestDistance = cityDistance[i];
  }
  meanDistance = sum / cityDistance.size();
  cout << "The sum of all distances is: " << sum << endl;
  cout << "The smallest distance between two neighboring cities: " << smallestDistance << endl;
  cout << "The greatest distance between two neighboring cities: " << greatestDistance << endl;
  cout << "The mean distance between two neighboring cities: " << meanDistance << endl;
  return 0;
}
