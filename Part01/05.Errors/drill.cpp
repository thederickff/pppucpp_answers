#include "../std_lib_facilities.h"

int main()
{

  try {

    // Code here
    // 01. Cout << "Success!\n";
    cout << "Success!\n";
    // 02. cout << "Success!\n;
    cout << "Success!\n";
    // 03. cout << "Success" << !\n"
    cout << "Success" << "!\n";
    // 04. cout << Success << '\n';
    cout << "Success!" << '\n';
    // 05. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
    int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
    // 06. vector<int> v(10); v(5) = 7; if(v(5) != 7) cout << "Success!\n";
    vector<int> u(10); u[5] = 7; if(u[5] != 7) cout << "Success!\n";
    // 07. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
    if (true) cout << "Success!\n"; else cout << "Fail!\n";
    // 08. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    // 09. string s = "ape"; bool c = "fool" < s; if (c) cout << "Success!\n";
    string s = "ape"; bool f = "fool" < s; if (f) cout << "Success!\n";
    // 10. string s = "ape"; if (s == "fool") cout << "Success!\n";
    string t = "ape"; if (t != "fool") cout << "Success!\n";
    // 11. string s = "ape"; if (s == "fool") cout < "success!\n";
    string w = "ape"; if (w != "fool") cout << "Success!\n";
    // 12. string s = "ape"; if (s+"fool") cout < "Success!\n";
    string z = "ape"; if (z != "fool") cout << "Success!\n";
    // 13. vector<char> d(5); for (int i =0; i < d.size(); ++i); cout << "Success!\n";
    vector<char> d(5); d[0] = 'd'; for (int i =0; i < d.size(); ++i) cout << "Success!\n";

    return 0;
  } catch (exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }

  return 0;
}
