/*
  Draw a two-dimensional house seen from the front, the way a child would: with
  a door, two windows, and a roof with a chimney. Feel free to add details;
  maybe have "smoke" come out of the chimney.
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  int ifx = 160, ify = 150;

  //int width_front = 400, width_front = 260;
  Simple_window win{Point(350, 160), 640, 480, "Exercise #7 - Two-dimensional House"};

  Rectangle sky{Point(0, 0), win.x_max(), ify + 100};
  sky.set_fill_color(Color::dark_blue);
  Rectangle grass{Point(0, ify + 100), win.x_max(), win.y_max() - ify + 100};
  grass.set_fill_color(Color::dark_green);

  Rectangle front{Point(ifx, 150), 320, 180};
  front.set_fill_color(Color::dark_cyan);

  Rectangle chimney{Point(ifx + front.width()-50, ify-60), 30, 60};
  chimney.set_fill_color(Color::dark_yellow);

  Polygon roof;
  roof.add(Point(ifx, ify));
  roof.add(Point(ifx + front.width(), ify));
  roof.add(Point(ifx + (front.width() / 2), ify - 60));
  roof.set_fill_color(Color::dark_red);

  Rectangle door{Point(ifx + (front.width() / 2) - 20, ify + front.height() - 80), 40, 80};
  door.set_fill_color(Color::dark_magenta);

  int iwy = ify + front.height() - 70;
  Rectangle window1{Point(ifx + (front.width() / 2) - (front.width() / 3), iwy), 40, 40};
  window1.set_fill_color(Color::blue);
  Rectangle window2{Point(ifx + (front.width() / 2) + (front.width() / 4)-10, iwy), 40, 40};
  window2.set_fill_color(Color::blue);

  win.attach(sky);
  win.attach(grass);
  win.attach(front);
  win.attach(chimney);
  win.attach(roof);
  win.attach(door);
  win.attach(window1);
  win.attach(window2);
  win.wait_for_button();
  return 0;
}
