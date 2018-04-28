/*
  Write a program to read a file of whitspace-separated numbers and output them
  in order (lowest value first), one value per line. Write a value only once,
  and if it occurs more than once write the count of its occurences on its line.
  For example, 7 5 5 7 3 117 5 should give

  3
  5   3
  7   2
  117
*/
#include "std_lib_facilities.h"

struct Number {
  double number;
  int occurences;

  Number(double num) : number(num), occurences(1) { }
};

bool operator<(const Number& a, const Number& b)
{
  return a.number < b.number;
}

bool exists(double num, vector<Number>& numbers)
{
  for (Number& number : numbers) {
    if (num == number.number) {
      number.occurences++;
      return true;
    }
  }
  return false;
}

int main()
{
  try {
    string filename;
    cout << "Input a filename: ";
    cin >> filename;

    ifstream ifs {filename};
    if (!ifs) error("Can't open file ", filename);

    vector<Number> numbers;

    while (ifs) {
      double num;
      ifs >> num;

      if (ifs.good()) {
        if (!exists(num, numbers)) {
            Number number{num};
            numbers.push_back(number);
        }
      } else if (ifs.fail()){
        ifs.clear();
        char ch;
        ifs >> ch;
      }
    }

    sort(numbers);
    for (Number& number : numbers) {
      cout << number.number;
      if (number.occurences > 1) {
        cout << '\t' << number.occurences;
      }
      cout << '\n';
    }

  } catch (exception& e) {
    cerr << e.what() << '\n';
  }


  return 0;
}
