/*
  Define the right triangle class, Make an octagonal shape out of eight right
  triangles of different colors.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 40}, win_width, win_height, "Exercise 14 - Chapter 13: Graphics Classes");

  try
  {
    Right_triangle rt(Point{200, 250}, 40, 40, 0);


    win.attach(rt);
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
