/*
  Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
*/
#include "Custom_shapes.h"

int main()
{
  constexpr int win_width = 800;
  constexpr int win_height = 600;

  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 01 - Chapter 13: Graphics Classes");

  try
  {
    Arc arc({500, 200}, 250, 150, 180);

    win.attach(arc);

    win.wait_for_button();
  }
  catch (const exception& e)
  {
    Text error_message(Point{150, 200}, "Exception caught: ");
    Text error_message_detail(Point{250, 200}, e.what());

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
