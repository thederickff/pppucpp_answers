/*
  Define a class Regular_polygon. Use the center, the number of sides (>2), and
  the distance from the center to a corner as constructor arguments.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 10 - Chapter 13: Graphics Classes");

  try
  {
    //Regular_polygon rh2(Point{400, 310}, 2, 60);
    Regular_polygon rp3(Point{400, 310}, 3, 60);
    Regular_polygon rp4(Point{200, 260}, 4, 60);
    Regular_polygon rp5(Point{200, 150}, 5, 50);
    Regular_polygon rp6(Point{400, 150}, 6, 90);
    Regular_polygon rp8(Point{150, 450}, 8, 140);
    rp3.set_fill_color(Color::yellow);
    rp4.set_fill_color(Color::dark_cyan);
    rp5.set_fill_color(Color::magenta);
    rp6.set_fill_color(Color::green);
    rp8.set_fill_color(Color::dark_blue);
    //win.attach(rp2);
    win.attach(rp3);
    win.attach(rp4);
    win.attach(rp5);
    win.attach(rp6);
    win.attach(rp8);
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
