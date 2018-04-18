/*
  Write a program that reads a text file and converts its input to all lower
  case, producing a new file.
*/
#include "std_lib_facilities.h"

int main()
{
  string file;
  cout << "Type the name of a file which you want to 'lowercase': ";
  cin >> file;

  ifstream ifs {file};
  if (!ifs) error("Failed to open file ", file);

  ofstream ofs {string("output_") + file};

  string line;
  while (ifs) {
    getline(ifs, line);
    for (char& ch : line) {
      if (!isspace(ch))
        ch = tolower(ch);
      ofs << ch;
    }
    ofs << '\n';
  }

  return 0;
}
