/*
  Write a program that given a file name and a word outputs each line that
  contains that word together with the line number. Hint: getline().
*/
#include "std_lib_facilities.h"

int main()
{
  string filename, word;
  cout << "To see every line that contains a specific word of a file, type: [filename] [word]\n> ";
  cin >> filename >> word;

  ifstream ifs {filename};
  if (!ifs) error("Failed to read filename ", filename);

  int line_num = 1;
  while (ifs) {
    string line;
    getline(ifs, line);

    stringstream ss(line);
    ostringstream osw;
    for (char ch; ss >> ch; ) {
      if (isspace(ch)) {
        osw.str("");
      }
      osw << ch;
      if (word == osw.str()) {
        cout << line_num << " " << line << '\n';
      }
    }
    line_num++;
  }


  return 0;
}
