/*
  Design and implement a Name_pairs class holding(name, age) where name is a
  string and age is a double. Represent that as a vector<string> (called name)
  and a vector<double> (called age) member. Provide an input operation
  read_names() that reads a series of names. Provide a read_ages() operation
  that prompts the user for an age for each name. Provide a print() operation
  that prints out the (name[i], age[i]) pairs (one per line) in the order
  determined by the name vector. Provide sort() operation that sorts the name
  vector in alphabetical order and reorganizes age vector to match. Implement
  all "operations" as member functions. Test the class (of course: test early
  and often).
*/
#include "../std_lib_facilities.h"

class Name_pairs
{
public:
  void read_names();
  void read_ages();
  void print();
  void sortArrays();
private:
  vector<string> name;
  vector<double> age;
};

void Name_pairs::read_names()
{
  int index = 1;
  cout << "Type few names, type '||' to stop.\n";
  for (string input; ; ++index) {
    cout << "#" << index << " Name: ";
    cin >> input;
    if (input == "||") break;
    name.push_back(input);
  }
}

void Name_pairs::read_ages()
{
  for (int i = 0; i < name.size(); ++i) {
    double lage;
    cout << name[i] << "'s age: ";
    if (cin >> lage) {
      age.push_back(lage);
    }
  }
}

void Name_pairs::print()
{
  cout << "\n##################\n";
  for (int i = 0; i < name.size(); ++i) {
    cout << name[i] << " has " << age[i] << " years old.\n";
  }
}

void Name_pairs::sortArrays()
{
  cout << "\nSorting Name_pairs...\n";
  vector<string> copyName = name;
  vector<double> copyAge = age;
  sort(name);
  for (int i = 0; i < name.size(); i++) {
    for (int j = 0; j < name.size(); j++) {
      if (name[i] == copyName[j]) {
        age[i] = copyAge[j];
      }
    }
  }
}

int main()
{
  Name_pairs name_pairs;

  name_pairs.read_names();
  name_pairs.read_ages();
  name_pairs.print();
  name_pairs.sortArrays();
  name_pairs.print();
  return 0;
}
