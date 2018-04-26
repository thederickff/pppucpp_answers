/*
  Write a program that reads a text file and writes out how many characters of
  each character classification (§11.6) are in the file.
*/
#include "std_lib_facilities.h"

int main()
{
  string filename;
  cout << "Input a filename: ";
  cin >> filename;
  ifstream ifs {filename};

  if (!ifs) error("Failed to read file ", filename);

  int whitespaces = 0, letters = 0, decimal_digits = 0, hexadecimal_digits = 0;
  int uppercases = 0, lowercases = 0, letter_or_decimal = 0, control_chars = 0;
  int puncts = 0, printables = 0, graphs = 0;

  while (ifs) {
    string line;
    getline(ifs, line);
    for (char& ch : line) {
      if (isspace(ch)) { // whitespace (' ', '\t', 'n')
        whitespaces++;
      }
      if (isalpha(ch)) { // letter ('a' .. 'z', 'A' .. 'Z') (note: not '_')
        letters++;
      }
      if (isdigit(ch)) { // decimal digit ('0' .. '9')
        decimal_digits++;
      }
      if (isxdigit(ch)) { // hexadecimal digit (decimal digit or 'a' .. 'f', 'A' .. 'F')
        hexadecimal_digits++;
      }
      if (isupper(ch)) { // uppercase letter ('A' .. 'Z')
        uppercases++;
      }
      if (islower(ch)) { // lowercase letter ('a' .. 'z')
        lowercases++;
      }
      if (isalnum(ch)) { // letter or decimal digit
        letter_or_decimal++;
      }
      if (iscntrl(ch)) { // control character (ASCII 0..31 and 127)
        control_chars++;
      }
      if (ispunct(ch)) { // not a letter, digit, or whitespace, or invisible control character
        puncts++;
      }
      if (isprint(ch)) { // printable (ASCII ' '..'~')
        printables++;
      }
      if (isgraph(ch)) { // is isalpha(ch) or isdigit(ch) or ispunct(ch) (note: not space)
        graphs++;
      }
    }
  }
cout << "---------------------------------\n";
  cout << "Classification\t\tQuantity\n";
  cout << "---------------------------------\n";
  cout << "Whitespace\t\t"      << setw(9) << whitespaces << '\n';
  cout << "Alpha\t\t\t"         << setw(9) << letters << '\n';
  cout << "Decimal\t\t\t"       << setw(9) << decimal_digits << '\n';
  cout << "Hexadecimal\t\t"     << setw(9) << hexadecimal_digits << '\n';
  cout << "Uppercase\t\t"       << setw(9) << uppercases << '\n';
  cout << "Lowercase\t\t"       << setw(9) << lowercases << '\n';
  cout << "Letter or decimal\t" << setw(9) << letter_or_decimal << '\n';
  cout << "Control Character\t" << setw(9) << control_chars << '\n';
  cout << "Punctuation\t\t"     << setw(9) << puncts << '\n';
  cout << "Printable\t\t"       << setw(9) << printables << '\n';
  cout << "Graph\t\t\t"         << setw(9) << graphs << '\n';


  return 0;
}
