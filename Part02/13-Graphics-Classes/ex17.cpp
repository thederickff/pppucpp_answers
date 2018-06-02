/*
  Do the previous exercise, but using hexagons of a few different colors.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 40}, win_width, win_height, "Exercise 15 - Chapter 13: Graphics Classes");

  try
  {
    Vector_ref<Regular_hexagon> rhs;
    int size = 40;

    for (int i = size; i < win.x_max(); i += size) {
      for (int j = size; j < win.y_max(); j += size) {
        rhs.push_back(new Regular_hexagon(Point{i, j}, size / 2));
        Regular_hexagon& rh = rhs[rhs.size() - 1];
        rh.set_fill_color(Color{i* (2 / j*2) + j - (130*i / 2) * 2});
        win.attach(rh);
      }
    }

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
