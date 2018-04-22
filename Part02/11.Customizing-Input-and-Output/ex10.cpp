/*
  Write a function vector<string> split(const string& s) that returns a vector
  of whitespace-sepatated substrings from the argument s.
*/
#include "std_lib_facilities.h"

vector<string> split(const string& s)
{
  vector<string> split;
  istringstream is {s};

  for (string w; is >> w; )
    split.push_back(w);

  return split;
}

int main()
{
  vector<string> words = split("if you write anything on your computer, you'll need to get gram**rly");

  for (string& w : words) {
    cout << w << '\n';
  }

  return 0;
}
