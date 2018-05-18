/*
  Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw().
  Each takes a Rectangle argument and returns a Point. These functions define
  "connection points" on and in the rectangle. For example, nw(r) is the
  northwest (top left) corner of a Rectangle r.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 04 - Chapter 13: Graphics Classes");

  try
  {
    //Arrow arrow0(Point{100, 200}, 50, 0);

    //win.attach(arrow0);

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
