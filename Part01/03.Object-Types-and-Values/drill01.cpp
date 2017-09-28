#include "../std_lib_facilities.h"

int main(){
  char f_sex = 0;
  string friend_name = "";
  string result;
  cout << "Enter a friend name: ";
cin >> friend_name;
  cout << "And also a friend sex m/f: ";
  cin >> f_sex;

  result = "If you see " + friend_name +" please ask ";
  if(f_sex == 'm'){
    result += "him";
  } else if(f_sex == 'f') {
    result += "her";
  }
  result += " to call me";
  cout << "\n" << result << "\n";
}
