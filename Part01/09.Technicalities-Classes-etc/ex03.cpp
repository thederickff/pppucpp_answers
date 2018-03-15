/*
  Replace Name_pairs::print() with a (global) operator << and define == and !=
  for Name_pairs.
*/
#include "../std_lib_facilities.h"

class Name_pairs
{
public:
  void read_names();
  void read_ages();
  void sortArrays();
  vector<string> getName() const { return name; }
  vector<double> getAge() const { return age; }
  bool operator==(const Name_pairs& other);
  bool operator!=(const Name_pairs& other);
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

bool Name_pairs::operator==(const Name_pairs& other)
{
  if (name.size() != other.getName().size()) return false;
  int matches = 0;
  for (int i = 0; i < name.size(); ++i) {
    if (name[i] == other.getName()[i]) matches++;
  }
  if (matches != name.size()) return false;

  return true;
}

bool Name_pairs::operator!=(const Name_pairs& other)
{
  return !(*this == other);
}

ostream& operator<<(ostream& os, Name_pairs& np)
{
  os << "\n#######################\n";
  for (int i = 0; i < np.getName().size(); ++i) {
    os << np.getName()[i] << " has " << np.getAge()[i] << " years old.\n";
  }
  return os;
}

int main()
{
  Name_pairs name_pairs;
  name_pairs.read_names();
  name_pairs.read_ages();
  cout << name_pairs;
  name_pairs.sortArrays();
  cout << name_pairs;

  Name_pairs name_pairs2;
  name_pairs2.read_names();
  name_pairs2.read_ages();
  name_pairs2.sortArrays();

  if (name_pairs == name_pairs2) {
    cout << "It is equal!\n";
  } else {
    cout << "It is not equal!\n";
  }
  return 0;
}
