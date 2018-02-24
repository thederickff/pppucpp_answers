/*
  Write versions of the functions from exercise 5, but with a vector<string>.
*/
#include "../std_lib_facilities.h"

void printVector(const vector<int>&, const string&);

void reverse1(vector<int> array)
{
  for (int i = 0; i < array.size(); ++i) {
    if (array[i] == array[array.size()-1-i]) {
      break;
    } else {
      swap(array[i], array[array.size()-1-i]);
    }
  }
  printVector(array, string("reverse 1"));
}
void reverse2(vector<int>& array)
{
  for (int i = 0; i < array.size(); ++i) {
    if (array[i] == array[array.size()-1-i]) {
      break;
    } else {
      swap(array[i], array[array.size()-1-i]);
    }
  }
  printVector(array, string("reverse 2"));
}

void printVector(const vector<int>& array, const string& label)
{
  cout << "---- Print " << label << " vector ----\n";
  for (const int &v : array) {
    cout << v << " ";
  }
  cout << '\n';
}
int main()
{
  vector<int> array{1, 3, 5, 7, 9};
  printVector(array, string("original"));
  reverse1(array);
  printVector(array, string("original"));
  reverse2(array);
  printVector(array, string("original"));
  return 0;
}
