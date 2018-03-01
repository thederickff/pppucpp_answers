/*
  Write a function that given two vector<double>s price and weight computes a
  value (an "index") that is the sum of all price[i]*weight[i]. Make sure to
  have weight.size() == price.size().
*/

#include "../std_lib_facilities.h"

void compute(const vector<double>& prices, const vector<double>& weights)
{
  if (prices.size() != weights.size()) {
    cout << "Couldn't compute value, make sure the vectors have the same size.\n";
    return;
  }

  double n = 0;

  for (int i = 0; i < prices.size(); ++i) {
    n += prices[i] * weights[i];
  }

  cout << "Index is " << n << '\n';
}

int main()
{
  vector<double> prices = {2.34, 0.92, 0.45, 1.59, 4.29};
  vector<double> weights = {0.8, 0.5, 1.5, 2.5, 5.0};

  compute(prices, weights);

  return 0;
}
