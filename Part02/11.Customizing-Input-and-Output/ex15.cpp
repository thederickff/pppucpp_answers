/*
  Write a program that reads a file of whitespace-separated numbers and outputs
  a file of numbers using scientific format and precision 8 in four fields of 20
  characters per line.
*/
#include "std_lib_facilities.h"

int main()
{
  try {
    string filename;
    cout << "Input a filename: ";
    cin >> filename;

    ifstream ifs {filename};
    if (!ifs) error("Can't open file ", filename);

    vector<double> numbers;

    while (ifs) {
      double number;
      ifs >> number;

      if (ifs.good()) {
          numbers.push_back(number);
      } else if (ifs.fail()){
        ifs.clear();
        char ch;
        ifs >> ch;
      }
    }

    cout << scientific << setprecision(8);
    for (int i = 0; i < numbers.size(); ++i) {
      cout << setw(20) << numbers[i];
      if (i % 4 == 3) {
        cout << '\n';
      }
    }
    cout << '\n';

  } catch (exception& e) {
    cerr << e.what() << '\n';
  }

  return 0;
}
