/*
  Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a
  300-pixel-long y axis through the center of the ellipse. Mark the foci.
  Mark a point on the ellipse that is not on one of the axes. Draw the two
  lines from the fonci to the point.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 20}, win_width, win_height, "Exercise 11 - Chapter 13: Graphics Classes");

  try
  {
    Super_Ellipse se(Point{300, 200}, 500, 50);

    win.attach(se);
    win.wait_for_button();
  }
  catch (const exception& e)
  {
    Text error_message(Point{150, 200}, "Exception caught: ");
    Text error_message_detail(Point{280, 200}, e.what());

    win.attach(error_message);
    win.attach(error_message_detail);
    win.wait_for_button();
  }
  catch (...)
  {
    Text error_message(Point{150, 200}, "unknown_exception caught!");

    win.attach(error_message);
    win.wait_for_button();
  }

  return 0;
}
