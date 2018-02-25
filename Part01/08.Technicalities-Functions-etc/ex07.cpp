/*
  Read five strings into a vector<string> name, then prompt the user for
  the ages of the people named and store the ages into a vector<double> age.
  Then print out the (name[i], age[i]) pairs. The tricky part here is to get
  the age vector in the correct order to match the sorted name vector. Hint:
  Before sorting name, take a copy and use that to make a copy of age in the
  right order after sorting name. Then, do that exercise again but allowing
  an arbitrary number of names.
*/

#include "../std_lib_facilities.h"

void promptNames(vector<string>& names, int n)
{
  for (int i = 0; i < n; ++i) {
    string name;
    cout << "#" << (i+1) << " Type a name: ";
    cin >> name;
    names.push_back(name);
  }
}

void promptAges(const vector<string>& names, vector<double>& ages)
{
  for (string name : names) {
    double age;
    cout << "Age of " << name << ": ";
    cin >> age;
    ages.push_back(age);
  }
}

void sortNames(vector<string>& names, vector<double>& ages)
{
  vector<string> oldNames = names;
  vector<double> oldAges = ages;

  sort(names);

  for (int i = 0; i < names.size(); ++i)
  {
    for (int j = 0; j < names.size(); ++j)
    {
      if (names[j] == oldNames[i]) {
        ages[j] = oldAges[i];
      }
    }
  }

}

int main()
{
  vector<string> names;
  vector<double> ages;

  promptNames(names, 10);
  promptAges(names, ages);

  sortNames(names, ages);

  cout << "\n###############################\n";
  for (int i = 0; i < names.size(); ++i) {
    cout << names[i] << " has " << ages[i] << " ages.\n";
  }

  return 0;
}
