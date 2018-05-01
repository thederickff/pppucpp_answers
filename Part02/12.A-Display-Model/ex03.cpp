/*
  Draw your initials 150 pixels high. Use a thick line. Draw each initial in
  different color.
*/
#include "Graph.h"
#include "Simple_window.h"

int main()
{
  Point tlc {350, 110};
  Simple_window win {tlc, 640, 480, "Exercise #3"};

  Text d(Point{185, 250}, "D");
  Text f1(Point{280, 250}, "F");
  Text f2(Point{350, 250}, "F");

  d.set_color(Color::dark_red);
  f1.set_color(Color::dark_blue);
  f2.set_color(Color::dark_green);

  d.set_font_size(150);
  f1.set_font_size(150);
  f2.set_font_size(150);

  win.attach(d);
  win.attach(f1);
  win.attach(f2);
  win.wait_for_button();

  return 0;
}
