/*
  Define a class Poly that represents a polygon but checks that its points
  really do make a polygon in its constructor. Hint: You'll have to supply the
  points to the constructor.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 40}, win_width, win_height, "Exercise 15 - Chapter 13: Graphics Classes");

  try
  {
    Poly poly({
      Point{20, 20},
      Point{20, 40},
      Point{40, 40},
      Point{40, 20}
    });
    win.attach(poly);

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
