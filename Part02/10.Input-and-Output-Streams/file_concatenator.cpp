/*
  Write a program that accepts two file names and produce a new file that is the
  contents of the first file followed by the contents of the second; that is,
  the program concatenates the two files.
*/
#include "std_lib_facilities.h"

int main()
{
  string iname1, iname2;
  cout << "Please enter a file two files separated by white space:";
  cin >> iname1 >> iname2;
  if (!cin) error("Could not not read file names");

  ifstream ifs1 {iname1};
  ifstream ifs2 {iname2};
  ofstream ofs {"output_file.txt"};
  if (!ofs) error("could not open output file");
  if (!ifs1 || !ifs2) error("Could not open input files");

  for (string content; ifs1 >> content; ) {
    ofs << content;
  }

  for (string content; ifs2 >> content; ) {
    ofs << content;
  }

  return 0;
}
