/*
  Reverse the order of words (defined as whitespace-separated strings) in a
  file. For example, Norwegian Blue parrot becomes parrot Blue Norwegian. You
  are allowed to assume that all the strings from the file will fit into memory
  at once.
*/
#include "std_lib_facilities.h"

struct Line {
  vector<string> words;
};

int main()
{
  string filename;
  cout << "Input a filename: ";
  cin >> filename;
  ifstream ifs {filename};

  if (!ifs) error("Failed to read file ", filename);

  vector<Line> lines;
  while (ifs) {
    Line line;

    string str;
    getline(ifs, str);

    istringstream iss {str};

    for (string word; iss >> word; ) {
      line.words.push_back(word);
    }

    lines.push_back(line);
  }

  ofstream ofs { string("output_") + filename};
  for (int i = lines.size()-2; i >= 0; --i) { // 2 offsets because files generally has a empty line
    for (int j = lines[i].words.size()-1; j >= 0; --j) {
      ofs << lines[i].words[j] << ' ';
    }
    ofs << '\n';
  }

  cout << "File written successfully!\n";

  return 0;
}
