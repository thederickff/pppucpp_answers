/*
* If you haven't done so already, do the Try this exercises from this chapter.
*/
#include "../std_lib_facilities.h"

int main()
{
  cout << "Please enter your first name and age" << endl;
  string first_name = "???"; // string variable
                             //("???" means "don't know the name")
  double age = -1;  // double variable (-1 means "don't know the age")
  cin >> first_name >> age;
  age *= 12;
  cout << "Hello, " << first_name << "(age " << age << " months)" << endl;

  return 0;
}
