/*
  Write a function that takes an vector<string> argument and returns a
  vector<int> containing the number of characters in each string. Also find the
  longest and the shortest string and the lexicographically first and last
  string. How many separate functions would you use for these tasks? Why?

  Four separate functions, one for each task.
  Because that way a function would do only one thing.
*/
#include "../std_lib_facilities.h"


vector<int> toCharactersLength(const vector<string>& strs)
{
  vector<int> lengths;// = new vector<int>;

  for (string str : strs)
  {
    lengths.push_back(str.length());
  }

  return lengths;
}

string longest(const vector<string>& array, const vector<int>& lengths)
{
  int longest = 0, index = -1;
  for (int i = 0; i < array.size(); ++i)
  {
    if (lengths[i] > longest)
    {
      longest = lengths[i];
      index = i;
    }
  }

  return array[index];
}

string shortest(const vector<string>& array, const vector<int>& lengths)
{
  int shortest = 255, index = 0;

  for (int i = 0; i < array.size(); ++i)
  {
    if (lengths[i] < shortest) {
      shortest = lengths[i];
      index = i;
    }
  }

  return array[index];
}

string first(vector<string> array, const vector<int>& lengths)
{
  sort(array);

  return array[0];
}

string last(vector<string> array, const vector<int>& lengths)
{
  sort(array);

  return array[array.size()-1];
}

void printArray(const vector<string>& array, const vector<int> lengths)
{
  for (int i = 0; i < array.size(); ++i)
  {
    cout << array[i] << " has " << lengths[i] << " characters\n";
  }
}

int main()
{
  vector<string> names = {"Derick", "Cherno", "Ana", "Alane", "Alana", "millions", "Linter", "asset", "zzzz"};
  vector<int> lengths = toCharactersLength(names);

  printArray(names, lengths);

  cout << "Longest: " << longest(names, lengths) << '\n';
  cout << "Shortest: " << shortest(names, lengths) << '\n';
  cout << "Lexicographically first: " << first(names, lengths) << '\n';
  cout << "Lexicographically last: " << last(names, lengths) << '\n';

  return 0;
}
