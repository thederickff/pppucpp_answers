/*
  Write a program that reads a text file and writes out how many characters of
  each character classification (§11.6) are in the file.
*/
#include "std_lib_facilities.h"

int main()
{
  string filename;
  cout << "Input a filename: ";
  cin >> filename;
  ifstream ifs {filename};

  if (!ifs) error("Failed to read file ", filename);
  // ...
  ofstream ofs { string("output_") + filename};
  // ...
  cout << "File written successfully!\n";

  return 0;
}
