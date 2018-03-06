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

void print_until_ss(const vector<string>& v, const string& quit)
{
  int occurence = 0;
  for (string s : v) {
    if (s == quit) occurence++;
    if (occurence > 1) return;
    cout << s << '\n';
  }
}

int main()
{
  vector<string> array = {"a", "b", "c", "b", "d", "e", "f", "g", "h", "a"};
  cout << "print_until_s()\n";
  print_until_s(array, "b");
  cout << "print_until_ss()\n";
  print_until_ss(array, "b");

  return 0;
}
