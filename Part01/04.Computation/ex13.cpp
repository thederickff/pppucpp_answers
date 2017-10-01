/*
* Write a program that takes an input value n and then find the first n primes.
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
  int n;
  cout << "Prime numbers finder, enter the first prime numbers: " << endl;
  cin >> n;
  int max = 0;
  for (int i = 0; max < n; i++) {
      if(isPrime(i)) {
        primes.push_back(i);
        max++;
      }
  }

  cout << "Prime numbers found!" << endl;
  for (int prime : primes) {
    cout << prime << endl;
  }
  return 0;
}
