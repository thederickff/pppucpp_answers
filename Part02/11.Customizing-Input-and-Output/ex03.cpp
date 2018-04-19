/*
  Write a program that removes all vowels from a file ("disemvowels"). For example,
  Once upon a time! becomes nc pn tm!. Surprisingly often, the result is still
  readable; try it on your friends.
*/
#include "std_lib_facilities.h"

bool isvowel(char ch)
{
  switch (ch) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      return true;
  }
  return false;
}

int main()
{
  string filename;
  cout << "Type a filename: ";
  cin >> filename;

  ifstream ifs {filename};
  if (!ifs) error("failed to open the file ", filename);

  vector<string> lines;

  while (ifs) {
    string line;
    getline(ifs, line);
    lines.push_back(line);
  }

  ofstream ofs {string("output_") + filename};
  if (!ofs) error("Failed to open file for writing");

  for (string& line : lines) {
    ostringstream oss;
    for (char& ch : line) {
      if (!isvowel(ch)) {
        oss << ch;
      }
    }
    ofs << oss.str() << '\n';
  }
  
  return 0;
}
