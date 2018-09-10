/*
    Define a class to be regular octagon. Write a test that exercises all of its 
    functions (as defined by you or inherited from Shape).
*/
#include "Custom_objects.h"

int main()
{
  Simple_window win(Point{250, 50}, win_width, win_height, "Exercise 08 - Chapter 14: Graphics Class Design");

  try
  {
    Octagon oct(Point{200, 200}, 50);

    win.attach(oct);
    win.wait_for_button();
  }
  catch (const exception& e)
  {
    Text em(Point{150, 200}, "Exception caught: ");
    Text emd(Point{280, 200}, e.what());
    win.attach(em);
    win.attach(emd);
    win.wait_for_button();
  }
  catch (...)
  {
    Text em(Point{150, 200}, "Unknown exception caught!");
    win.attach(em);
    win.wait_for_button();
  }

  return 0;
}
