/*
  Define an abstract class and try to define an object of that type. What
  happens?

  Class Abstract1 gives a compiler error, `Abstract1::Abstract1()` is protected
  within this context

  Class Abstract2 gives a compile error, cannot declare `abst2` to be of
  abstract type `Abastract2`:
      class Abstract2     note: because the following virtual functions are pute
                                within `Abstract`.
*/
#include <iostream>

class Abstract1
{
public:
  void PrintMessage();
protected:
  Abstract1();
};

class Abstract2
{
public:
  virtual void PrintMessage() = 0;
}

void Abstract1::PrintMessage()
{
  std::cout << "Abstract1::printMessage(): Hello!" << std::endl;
}

int main()
{
  //Abstract1 abst1;
  //abst1.PrintMessage();
  Abstract2 abst2;
  abst2.PrintMessage();

  return 0;
}
