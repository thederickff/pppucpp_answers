/*
  Write a program that replaces punctuation with whitespace. Consider . (dot),
  semicolon (;), , (comma), ? (question mark), - (dash), ' (single quote)
  punctuation characters. Don't modify characters within a pair of double quotes
  ("). For example, "- dont't use the as-if rule." becomes " don t use the as if
  rule".
*/
#include "std_lib_facilities.h"

int main()
{
  string filename;
  cout << "Input a filename: ";
  cin >> filename;

  ifstream ifs {filename};
  if (!ifs) error("Could not open file for read: ", filename);

  ofstream ofs {string("output_") + filename};
  if (!ofs) error("Could not write to output file!");

  while (ifs) {
    string line;
    getline(ifs, line);

    for (char& ch : line) {
      if (ch == '\"' || !ispunct(ch)) {
        ofs << ch;
      } else {
        ofs << ' ';
      }
    }

    ofs << '\n';
  }

  cout << "File written successfully\n";

  return 0;
}
