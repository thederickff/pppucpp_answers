/*
  Write versions of the functions from exercise 5, but with a vector<string>.
*/
#include "../std_lib_facilities.h"

void printVector(const vector<string>&, const string&);

void reverse1(vector<string> array)
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
void reverse2(vector<string>& array)
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

void printVector(const vector<string>& array, const string& label)
{
  cout << "---- Print " << label << " vector ----\n";
  for (const string &v : array) {
    cout << v << " ";
  }
  cout << '\n';
}
int main()
{
  vector<string> array{"a", "b", "c", "d", "e"};
  printVector(array, string("original #1"));
  reverse1(array);
  printVector(array, string("original #2"));
  reverse2(array);
  printVector(array, string("original #3"));
  return 0;
}
