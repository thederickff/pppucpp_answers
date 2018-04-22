/*
  Split the binary I/O program from §11.3.2 into two; one program that converts
  an ordinary text file into binary and one program that reads binary and
  converts it into text. Test these programs by comparing text file with what
  you get by converting it to binary and back.
*/
#include "std_lib_facilities.h"

int main()
{
  cout << "Please enter input file name\n";
  string iname;
  cin >> iname;
  ifstream ifs {iname, ios_base::binary}; // note: stream mode
      // binary tells the stream not to try anything clever with the bytes
  if (!ifs) error("can't open input file name ", iname);

  // open an ostream for binary ouput to a file:
  cout << "Please enter output file name\n";
  string oname;
  cin >> oname;
  ofstream ofs {oname, ios_base::binary}; // note: stream mode
      // binary tells the stream not to try anything clever with the bytes
  if (!ofs) error("can't open output file ", oname);

  vector<int> v;

  // read from binary file:
  for (int x; ifs.read(as_bytes(x), sizeof(int)); ) // note: reading bytes
    v.push_back(x);

  // ... do something with v ...

  // write to binary file:
  for (int x : v)
      ofs.write(as_bytes(x), sizeof(int));  // note: writing bytes

  return 0;
}
