/*
  Define two classes Smiley and Frowny, which are both derived from class Circle
  and have two eyes and a mouth. Next, derive classes from Smiley and Frowny
  which add an appropriate hat to each.
*/
#include "Custom_objects.h"

int main()
{
  Simple_window win(Point{250, 50}, win_width, win_height, "Exercise 01 - Chapter 14: Graphics Class Design");

  try
  {
    Smiley smiley(Point{200, 150}, 50);
    Frowny frowny(Point{400, 150}, 50);

    SmileyWithHat smileyWithHat(Point{200, 300}, 50);
    FrownyWithHat frownyWithHat(Point{400, 300}, 50);

    win.attach(smiley);
    win.attach(frowny);
    win.attach(smileyWithHat);
    win.attach(frownyWithHat);
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
