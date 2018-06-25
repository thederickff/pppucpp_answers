/*
  Define a Stripped_circle using the technique from Stripped_rectangle.
*/
#include "Custom_objects.h"

int main()
{
  Simple_window win(Point{250, 80}, win_width, win_height, "Execise 06 - Chapter 14");

  try
  {
    Stripped_rectangle sr(Point{400, 100}, 200, 200);
    sr.set_fill_color(Color::dark_red);
    Stripped_circle sc(Point{200, 200}, 100);
    sc.set_fill_color(Color::green);
    win.attach(sr);
    win.attach(sc);
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

  return 0;
}
