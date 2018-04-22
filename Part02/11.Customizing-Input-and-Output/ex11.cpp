i/*
  Write a function vector<string> split(const string& s, const string& w) that
  returns a vector of whitespace-separated substrings from the argument s, where
  whitespace is defined as "ordinary whitespace" plus the characters in w.
*/
//#include "std_lib_facilities.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s, const string& w)
{
  vector<string> split;
  istringstream is {s};


  for (string w; is >> w; ) {
    ostringstream os;
    for (char& ch : w) {
      if (ch == ',') {
        if (os.str() != "") {
          split.push_back(os.str());
        }
        os.str("");
      } else {
        os << ch;
      }
    }
    if (os.str() != "") {
      split.push_back(os.str());
    }
  }

  return split;
}

int main()
{
  vector<string> words = split("if you write any,thing on your comp,uter, you'll need to get ,gram,rly,", ",");

  for (string& w : words) {
    cout << w << '\n';
  }

  return 0;
}
