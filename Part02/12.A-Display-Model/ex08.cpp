/*
  Draw the Olympic five rings. If you can't remember the colors, look them up.
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  Simple_window win(Point{300, 150}, 640, 480, "Exercise #8 - Olympic's five rings");

  int px = 18;
  int offsetX = 80;
  Circle ring1(Point{px * 7 + offsetX, 150}, 50);
  ring1.set_color(Color::blue);
  ring1.set_style(Line_style(Line_style::solid, 5));
  Circle ring2(Point{px * 10 + offsetX, 200}, 50);
  ring2.set_color(Color::yellow);
  ring2.set_style(Line_style(Line_style::solid, 5));
  Circle ring3(Point{px * 13 + offsetX, 150}, 50);
  ring3.set_color(Color::black);
  ring3.set_style(Line_style(Line_style::solid, 5));
  Circle ring4(Point{px * 16 + offsetX, 200}, 50);
  ring4.set_color(Color::green);
  ring4.set_style(Line_style(Line_style::solid, 5));
  Circle ring5(Point{px * 19 + offsetX, 150}, 50);
  ring5.set_color(Color::red);
  ring5.set_style(Line_style(Line_style::solid, 5));


  win.attach(ring1);
  win.attach(ring2);
  win.attach(ring3);
  win.attach(ring4);
  win.attach(ring5);
  win.wait_for_button();

  return 0;
}
