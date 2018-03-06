/*
  Improve print_until_s() from §8.5.2. Test it. What makes a good set of test
  cases? Give reasons. Then, write a print_until_ss() that prints until it sees
  a second occurence of its quit argument.
*/
#include "../std_lib_facilities.h"

void print_until_s(const vector<string>& v, const string& quit)
{
  for (string s : v) {
    if (s == quit) return;
    cout << s << '\n';
  }
}

int main()
{
  vector<string> array = {"a", "b", "c", "d", "e", "f", "g", "h"};

  print_until_s(array, "g");

  return 0;
}
