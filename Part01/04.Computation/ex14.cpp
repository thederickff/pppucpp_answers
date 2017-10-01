/*
* In the drill, you wrote a program that, given a series of numbers, found the
* max and min of that series. The number that appears the most times in a sequence
* is called the mode. Create a program that finds the mode of a set of positive
* integers
*/
#include "../std_lib_facilities.h"

// Global
vector<int> numbers;
int smallest =  100000;
int largest  = -100000;
int mode = 0;

int howMany(int n) {
  int quantity = 0;
  for (int i : numbers) {
    if (i == n) {
      quantity++;
    }
  }
  return quantity;
}
int main()
{

  cout << "Enter a few numbers: " << endl;
  for (int n; cin >> n;) {
    if (n < smallest) smallest = n;
    if (n > largest) largest = n;

    if(howMany(mode) < howMany(n)) {
      mode = n;
    }
    numbers.push_back(n);
  }

  cout << "Smallest: " << smallest << endl;
  cout << "Largest: " << largest << endl;
  cout << "Mode: " << mode << endl;

  return 0;
}
