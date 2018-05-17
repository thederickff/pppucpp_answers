/*
  Define a class Arrow, which draws a line with an arrowhead.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 03 - Chapter 13: Graphics Classes");

  try
  {
    Arrow arrow0(Point{100, 200}, 50, 0);
    Arrow arrow90(Point{200, 200}, 50, 90);
    Arrow arrow180(Point{300, 200}, 50, 180);
    Arrow arrow270(Point{350, 200}, 50, 270);
    Arrow arrow360(Point{400, 200}, 50, 360);

    Arrow arrow45(Point{100, 300}, 50, 45);
    Arrow arrow135(Point{200, 300}, 50, 135);
    Arrow arrow225(Point{250, 300}, 50, 225);
    Arrow arrow315(Point{300, 300}, 50, 315);

    Arrow arrow323(Point{100, 400}, 50, 323);
    Arrow arrow763(Point{200, 400}, 50, 763);
    Arrow arrow231(Point{300, 400}, 50, 231);
    Arrow arrow298(Point{400, 400}, 50, 298);

    win.attach(arrow0);
    win.attach(arrow90);
    win.attach(arrow180);
    win.attach(arrow270);
    win.attach(arrow360);

    win.attach(arrow45);
    win.attach(arrow135);
    win.attach(arrow225);
    win.attach(arrow315);

    win.attach(arrow323);
    win.attach(arrow763);
    win.attach(arrow231);
    win.attach(arrow298);

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
