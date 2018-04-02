/*
  Write a program that produces the sum of all the numbers in a file of
  whitespace-separated integers.
*/
#include "std_lib_facilities.h"

int main()
{
  string filename;
  cout << "Please type the name of a file with whitespace-separated integers: ";
  cin >> filename;
  ifstream ist {filename};
  if (!ist) error("Can't open input file ", filename);

  ist.exceptions(ist.exceptions()|ios_base::badbit);  //throw for bad
  int sum;
  for (int n; ist >> n; ) {
    cout << n << " ";
    sum += n;
  }

  cout << "\nSum: " << sum << '\n';
  return 0;
}
