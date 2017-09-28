#include "../std_lib_facilities.h"

int main(){

  string username;
  string name;
  string friend_name;
  string friend_call;
  char friend_sex = 0;
  int age = 0;

  cout << "Hello, enter your name: " << endl;
  cin >> username;
  cout << "Enter the name of the person you want to write to: " << endl;
  cin >> name;
  cout << "Recipient age: " << endl;
  cin >> age;
  cout << "Enter an friend name: " << endl;
  cin >> friend_name;
  cout << "Friend sex (m/f): " << endl;
  cin >> friend_sex;
  // Start the Letter
  cout << "Dear, " << name << endl;
  cout << "How are you? ";
  cout << "Have you seen " << friend_name << " lately?" << endl;
  // Friend Call Sentence
  friend_call = "If you see " + friend_name +" please ask ";
  if(friend_sex == 'm'){
    friend_call += "him";
  } else if(friend_sex == 'f') {
    friend_call += "her";
  }
  friend_call += " to call me";
  cout << friend_call << endl;
  // Age
  cout << "I hear you just had a birthday and you are " << age << " years old." << endl;
  if (age <= 0 || age >= 110) {
    simple_error("You're kidding!");
  }
  if ( age < 12 )
  {
    cout << "Next year you will be " << age + 1 << "." << endl;
  }
  if ( age == 17 )
  {
    cout << "Next year you will be able to vote." << endl;
  } else if (age < 70)
  {
    cout << "I hope you are enjoying retirement." << endl;
  }

  cout << "Yours sincerely,\n\n"<< username << endl;

  return 0;
}
