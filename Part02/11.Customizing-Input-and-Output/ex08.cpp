/*
  Write a program that replaces punctuation with whitespace. Consider . (dot), ;
  (semicolon), , (comma), ? (question mark), - (dash), ' (single quote)
  punctuation characters. Don’t modify characters within a pair of double quotes
  ("). For example, “- don't use the as-if rule.” becomes “ don t use the as if
  rule ”.
*/
#include "std_lib_facilities.h"

class Punct_stream {
public:
  Punct_stream(istream& s) : source(s) { }
  void add_whitespace(string s) {white += s;}
  string whitespace() {return white;}
  bool is_whitespace(char ch);
  Punct_stream& operator>>(string& s);
  operator bool();
private:
  istream& source;
  istringstream buffer;
  string white;
};

Punct_stream::operator bool()
{
  return !(source.bad()||source.fail()) && source.good();
}

bool Punct_stream::is_whitespace(char ch)
{
  for (char& c : white) if (c == ch) return true;
  return false;
}

Punct_stream& Punct_stream::operator>>(string& s)
{
  while(!(buffer>>s)) {
    if (buffer.bad() || !source.good()) return *this;
    buffer.clear();
    string line;
    getline(source, line);
    bool quote = false;
    for (char& ch : line) {
      if (ch == '\"') quote = quote ? false : true; //If there is a quote (") the characters won't be affected while there won't be a closing quote.
      if (!quote) {
        if (is_whitespace(ch)) ch = ' '; // Change the symbol to whitespace
        else tolower(ch); // Convert all letters of string to lowercase one
      }
    }
    istringstream is {line};
    string x, r;

    while(is >> r) {
      if (r == "don't") r = "do not";
      else if (r == "can't") r = "cannot";
      x += r + ' '; // Add whitespace between words
    }
    buffer.str(x);
  }

  return *this;
}

int main()
{
 vector<string> dictionary;
 Punct_stream ps {cin};
 ps.add_whitespace(";:,.?!()\"{}<>/&$@#%%^*|~");
 cout << "Input some words: (~~ to end input)\n";
 string s;
 while (ps >> s) if (s == "~~") break; dictionary.push_back(s);
 sort(dictionary);
 ofstream ofs {"output_ex08.txt"};
 for (string& x : dictionary) {
   ofs << x << '\n';
 }

  return 0;
}
