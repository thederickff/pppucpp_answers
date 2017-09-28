#include <iostream>

int main()
{

  int age;
  std::cout << "Type do digit your age: " << std::endl;
  std::cin >> age;

  if( age <= 0 || age >= 110)
  {
        std::cerr << "You're kidding!" << std::endl;
  }
  if ( age < 12 )
  {
    std::cout << "Next year you will be " << age + 1 << std::endl;
  }
  if ( age == 17 )
  {
    std::cout << "Next year you will be able to vote!" << std::endl;
  }
  if (age < 70)
  {
    std::cout << "I hope you are enjoying retirement" << std::endl;
  }

  std::cout << "Yours sincerely, \n" << std::endl << "Derick Felix" << std::endl;

  return 0;
}
