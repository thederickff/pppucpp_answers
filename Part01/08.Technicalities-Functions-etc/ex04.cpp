/*
  An int can hold numbers only up to a maximum number. Find an aproximation of
  that number by using fibonacci().
*/
#include "../std_lib_facilities.h"

void fibonacci(int x, int y, vector<int>& v, int n)
{
  if (v.size() > 0) return;
  v.push_back(x);
  v.push_back(y);
  int maxNumber = 0;
  for (int i = 0; i < n; ++i)
  {
    v.push_back(v[i] + v[i+1]);
  }
  for (int i = 0; i < v.size(); ++i)
  {
    if (v[i] < 0) maxNumber = v[i-1];
    cout << "v[" << i << "] = " << v[i] << '\n';
  }
  cout << "The aproximated max number an int can hold is " << maxNumber << '\n';
}

int main()
{
  vector<int> array;
  fibonacci(0, 1, array, 47);

  return 0;
}
