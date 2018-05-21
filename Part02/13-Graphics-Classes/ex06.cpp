/*
  Write a program that draws a class diagram like the one in §12.6. It will
  simplify matters if you start by defining a Box class that is a rectangle with
  a text label.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 06 - Chapter 13: Graphics Classes");

  try
  {
    Circle circle(Point{200, 200}, 50);

    win.attach(circle);
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
