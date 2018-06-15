/*
  Define a class Immobile_Circle, which is just like Circle but can't be moved.
*/
#include "Custom_objects.h"

int main()
{
  Simple_window win(Point{250, 50}, win_width, win_height, "Exercise 04 - Chapter 14: Graphics Class Design");

  try
  {
    Circle circle(Point{200, 250}, 100);
    Immobile_Circle icircle(Point{400, 250}, 100);

    win.attach(circle);
    win.attach(icircle);
    win.wait_for_button();
    circle.move(50, 100);
    icircle.move(-50, 100);
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
