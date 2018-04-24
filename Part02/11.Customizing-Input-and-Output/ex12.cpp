/*
  Reverse the order of characters in a text file. For example, asdfghjkl becomes
  lkjhgfdsa. Warning: There is no really good, portable, and efficient way of
  reading a file backward.
*/
#include "std_lib_facilities.h"

struct Line
{
  string line;
  vector<char> characters;
};

int main()
{
  try {
    string filename;
    cout << "Input a filename: ";
    cin >> filename;

    ifstream is {filename};

    if (!is) error("Can't open file ", filename);

    vector<Line> lines;

    while(is)
    {
      Line line;

      getline(is, line.line);
      line.characters.reserve(line.line.size());
      for (char& ch : line.line)
      {
        line.characters.push_back(ch);
      }
      lines.push_back(line);
    }

    ofstream os {string("output_") + filename};
    if (!os) error("Can't write to file ", filename);

    // (lines.size()-2) because files generally has their last line empty
    for (int i = lines.size()-2; i >= 0; --i)
    {
        Line& line = lines[i];

        for (int j = line.characters.size()-1; j >= 0; --j)
        {
          char& ch = line.characters[j];
          os << ch;
        }

        os << '\n';
    }
  } catch (exception& e) {
    cerr << e.what() << endl;
  }

  return 0;
}
