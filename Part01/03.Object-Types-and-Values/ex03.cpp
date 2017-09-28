/*
* Write a program that doesn't anything, but declares a number of variables with
* legal and ilegal names (such as int double = 0;), so that you can see how the
* compiler reacts
*/
#include "../std_lib_facilities.h"

int main()
{
  int double = 10;

  int catch = exception;

  string name = 23.40;
  int how = 'c';
  char you = "Do that";
  bool true = false;
  bool switchcase = 31;
  
  return 0;
}
