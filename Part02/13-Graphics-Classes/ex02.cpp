/*
  Draw a box with rounded corners. Define a class Box, consisting, of four lines
  and four arcs.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 02 - Chapter 13: Graphics Classes");

  try
  {
    //Arc arc({500, 200}, 150, 150, 90, 180);
    Box box({300, 200}, 50, 50);

    //win.attach(arc);
    win.attach(box);

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
