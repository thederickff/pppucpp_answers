/*
  Tile a part of a window with Regular_hexagons (use at least eight hexagons).
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 10 - Chapter 13: Graphics Classes");

  try
  {
    Vector_ref<Regular_hexagon> rhs;

    int x_max = win.x_max();
    int y_max = win.y_max();

    for (int i = 60; i < 600; i += 60)
    {
      for (int j = 60; j < 300; j += 65)
      {
        rhs.push_back(new Regular_hexagon(Point{i, j}, 30));
        int index = rhs.size() - 1;
        if (index % 2 == 0) {
          rhs[index].set_fill_color(Color::dark_red);
        } else {
          rhs[index].set_fill_color(Color::dark_blue);
        }
        win.attach(rhs[index]);
      }
    }

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
