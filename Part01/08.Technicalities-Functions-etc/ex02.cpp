/*
  Write a function print() that prints a vector of ints to cout. Give it two
  arguments: a string for "labeling" the output and a vector.

*/
#include "../std_lib_facilities.h"

void print(const string& label, vector<int>& array)
{
  cout << label << '\n';
  for (int i = 0; i < array.size(); ++i) {
    cout << array[i] << '\n';
  }
}

int main()
{

  vector<int> array;
  array.push_back(1);
  array.push_back(2);
  array.push_back(3);
  array.push_back(4);

  print("Dont't know...", array);
  return 0;
}
