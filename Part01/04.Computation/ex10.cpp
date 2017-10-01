/*
* Write a program that plays the game "Rock, Paper, Scissors". Real randomness is
* too hard to provide just now, so just build a vector with a sequence of values to
* be used as "the next values."
*/
#include "../std_lib_facilities.h"


int main()
{

  vector<int> cpu = {1, 3, 2, 2, 1};
  int user;
  int rounds = 0;


  cout << "Select one: " << endl;
  cout << "1. Rock" << endl;
  cout << "2. Paper" << endl;
  cout << "3. Scissors" << endl;
  while(rounds < 5) {

    cin >> user;
    if(user < 1 || user > 3) {
      simple_error("You entered unknown type!");
    }
    if (cpu[rounds] == user) {
      cout << "draw" << endl;
    } else if ((cpu[rounds] == 1 && user == 2) || (cpu[rounds] == 2 && user == 3) || (cpu[rounds] == 3 && user == 1)) {
      cout << "You won!" << endl;
    } else {
      cout << "You lost!" << endl;
    }
    rounds++;
    cout << "Round: " << rounds << endl;
  }
  return 0;
}
