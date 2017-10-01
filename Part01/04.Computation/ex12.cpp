/*
* Modify the program described in the previous exercise to take an input value
* max and then find all prime numbers from 1 to max
*/
#include "../std_lib_facilities.h"

bool isPrime(int n)
{
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i < n; i++) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

int main()
{
  vector<int> primes;
  int max;
  cout << "Prime numbers finder, enter a max value: " << endl;
  cin >> max;

  for (int i = 0; i < max; i++) {
      if(isPrime(i)) {
        primes.push_back(i);
      }
  }

  cout << "Prime numbers found!" << endl;
  for (int prime : primes) {
    cout << prime << endl;
  }
  return 0;
}
