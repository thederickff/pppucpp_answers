#include "std_lib_facilities.h"

int main()
{
  cout << "Please enter input file name\n";
  string iname;
  cin >> iname;
  ifstream ifs {iname};
  if (!ifs) error("can't open input file name ", iname);

  // open an ostream for binary ouput to a file:
  cout << "Please enter output file name\n";
  string oname;
  cin >> oname;
  ofstream ofs {oname, ios_base::binary}; // note: stream mode
      // binary tells the stream not to try anything clever with the bytes
  if (!ofs) error("can't open output file ", oname);

  vector<string> v;

  for (string x; ifs >> x; )
    v.push_back(x);

  // ... do something with v ...

  // write to binary file:
  for (string& x : v)
      ofs.write(as_bytes(x), sizeof(string));  // note: writing bytes

  return 0;
}
