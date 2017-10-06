/*
* Pyramid writer
*    *
*   ***
*  *****
* *******
* By specifying how many layers
*/
#include <iostream>

using namespace std;

int main()
{
  int layers, repeatChar = 0;
  cout << "Type how many layers you want: " << endl;
  cin >> layers;

  // Write * on the middle of the pyramid on the first layer
  for (int i = 0; i < layers; i++) {
    cout << " ";
  }
  cout << " *" << endl;

  // Construct the pyramid
  for (int i = layers; i > 0; i--) {
    repeatChar++;
    // Write blank space until find the initial left side of the pyramid
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    // Write the left side of the pyramid
    for (int x = 0; x < repeatChar; x++) {
      cout << "*";
    }
    // Write * on the middle of the pyramid for each layer
    cout << "*";
    // Write the write side of the pyramid
    for (int x = 0; x < repeatChar; x++) {
      cout << "*";
    }
    cout << "\n";
  }

  return 0;
}
