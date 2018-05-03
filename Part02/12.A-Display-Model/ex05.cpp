/*
  Draw a red 1/4-inch frame around a rectangle that is three-quarters the height
  of your screen and two-thirds the width.
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  Simple_window win {{350,110}, x_max(), y_max(), "Exercise #5"};

  Rectangle frame({215, 45}, (x_max() / 3) * 2 + 10, (y_max() / 4) * 3 + 10);
  frame.set_color(Color::red);
  Rectangle rect({220, 50}, (x_max() / 3) * 2, (y_max() / 4) * 3);

  win.attach(frame);
  win.attach(rect);
  win.wait_for_button();

  return 0;
}
