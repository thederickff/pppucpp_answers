/*
  Write a program that takes two files containing sorted whitespace-separated
  words and merges them, preserving order.
*/
#include "std_lib_facilities.h"

int main()
{
  string file1, file2;
  cout << "Enter two file names separated by whitespace: ";
  cin >> file1 >> file2;
  if (!cin) cout << "Failed to read file names\n";
  ifstream ifs1 {file1};
  ifstream ifs2 {file2};
  ofstream ofs {"output_sorted.txt"};
  if (!ifs1) error("Failed to open input file ", file1);
  if (!ifs2) error("Failed to open input file ", file2);
  if (!ofs) error("Failed to open output file ", "output_sorted.txt");
  vector<string> words;
  for (string word; ifs1 >> word; ) {
    words.push_back(word);
  }
  if (ifs1.bad()) error("Could not read input file", file1);

  for (string word; ifs2 >> word; ) {
    words.push_back(word);
  }

  sort(words);

  if (ifs2.bad()) error("Could not read input file", file2);

  for (string word : words) {
    ofs << word << endl;
  }

  return 0;
}
