/*
* Write a program to play a numbers guessing game. The user thinks a number
* between 1 and 100 and your program ask questions to figure out what the number
* is. Your program should be able to identify the number after asking no more
* than seven questions.
*/
#include "../std_lib_facilities.h"

// Global
int answer;
int attempts = 0;

void makeAttempt(int n);
int main()
{
  cout << "Numbers guessing game. Enter a number between 1 and 100. I will try to figure out." << endl;
  cin >> answer;
  if(answer > 100 || answer < 0) {
    simple_error("You didn't do what you was supposed to");
  }

  makeAttempt(50);


  cout << "The number you have thought was " << answer << endl;


  return 0;
}

void makeAttempt(int n)
{
  if (attempts >= 7) {
      return;
  }
  if(answer == n) {
    cout << "I got your number!" << endl;
    attempts = 7;
    return;
  }

  cout << "Is the number you are thinking of less than "<< n << "? " << endl;
  attempts++;
  if (answer < n) {
    cout << "Yes" << endl;
    n++;
    makeAttempt(n-(n/2));
  } else {
    cout << "No" << endl;
    n++;
    makeAttempt(n+(n/2));
  }
}
