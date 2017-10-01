/*
* There is an old story that the emperor wanted to thank the inventor of the game
* of chess and asked the inventor to name his reward. the inventor asked for one
* grain of rice for the first square, 2 for the second, 4 for the third, and so on.
* Write a program to calculate how many squares are required to give the inventor
* at least 1000 grains of rice, at least 1,000,000 grains, ans at least 1,000,000,000
* grains.
*/
#include "../std_lib_facilities.h"

int main()
{


  double grains = 1;
  int squares;
  cout << "How many squares you want see? " << endl;
  cin >> squares;
  for (int i = 2; i <= squares; i++) {

    grains *= 2;

    cout << "Square: " << i << endl;
    cout << "Grains: " << grains << endl;
  }

  return 0;
}
