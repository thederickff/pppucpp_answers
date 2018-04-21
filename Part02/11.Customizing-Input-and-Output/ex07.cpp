/*
  Modify the program from the previous exercise so that it replaces don't with
  do not, can't with cannot, etc.; leaves hyphens within words intact (so that
  we get "do not use the as-if rule"); and converts all characters to lower
  case.
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
      ch = tolower(ch);
      if (ch == '\"' || ch == '-' || !ispunct(ch)) {
        ofs << ch;
      } else {
        if (ch == '\'') {
          ofs << 'o';
        } else {
          ofs << ' ';
        }
      }
    }

    ofs << '\n';
  }

  cout << "File written successfully\n";

  return 0;
}
