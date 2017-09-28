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
