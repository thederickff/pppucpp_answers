/*
* Create a program to find all the prime numbers between 1 and 100. Then write a
* loop that goes from 1 to 100, checks each number to see if it is a prime, and
* stores each prime found in a vector. Write another loop that lists the primes
* you found
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

  for (int i = 0; i < 100; i++) {
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
