/*
  Define a Stripped_rectangle where instead of fill, the rectangle is "filled"
  by drawing one-pixel-wide horizontal lines across the inside of the rectangle
  (say, draw every second line like that). You may have to play with the width
  of lines and the line spacing to get a pattern you like.
*/
#include "Custom_objects.h"

int main()
{
  Simple_window win(Point{250, 50}, win_width, win_height, "Exercise 05 - Chapter 14: Graphics Class Design");

  try
  {
    Stripped_rectangle srect(Point{200, 250}, 100, 100);
    srect.set_fill_color(Color::red);

    win.attach(srect);
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
