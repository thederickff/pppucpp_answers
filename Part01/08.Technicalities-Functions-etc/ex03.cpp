/*
  Create a vector of Fibonacci numbers and print them using the function from
  exercise 2. To create the vector, write a function, fibonacci(x, y, v, n),
  where integers x and y are ints, v is an empty vector<int>, and n is the
  number of elements to put into v; v[0] will be x and v[1] will be y. A
  Fibonacci number is one that is part of a sequence where each element is the
  sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2,
  3, 5, 8, 13, 21,.... Your fibonacci() function should make such a sequence
  starting with its x and y arguments.
*/
#include "../std_lib_facilities.h"

void fibonacci(int x, int y, vector<int>& v, int n)
{
  if (v.size() > 0) return;
  v.push_back(x);
  v.push_back(y);
  for (int i = 0; i < n; ++i)
  {
    v.push_back(v[i] + v[i+1]);
  }
  for (int i = 0; i < v.size(); ++i)
  {
    cout << "v[" << i << "] = " << v[i] << '\n';
  }
}

int main()
{
  vector<int> array;
  fibonacci(0, 1, array, 46);

  return 0;
}
