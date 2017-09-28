/**
* Write a program in C++ that converts from miles to kilometers. Your program should
* have a reasonable prompt for the user to enter a number of miles.
*/
#include <iostream>

int main()
{
  double mile;
  double kilometer;
  std::cout << "Type your desired amount of mile: " << std::endl;
  std::cin >> mile;
  kilometer = mile * 1.609;
  std::cout << mile << " amount of mile is the same of " << kilometer << " amount of kilometer" << std::endl;
  return 0;
}
