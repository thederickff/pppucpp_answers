/*
  "Tile" a window with small right triangles.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 40}, win_width, win_height, "Exercise 15 - Chapter 13: Graphics Classes");

  try
  {
    Vector_ref<Right_triangle> rts;
    int size = 20;

    for (int i = 0; i < win.x_max(); i += size) {
      for (int j = 40; j < win.y_max(); j += size) {
        rts.push_back(new Right_triangle(Point{i, j}, size, size, 180));
        Right_triangle& rt = rts[rts.size() - 1];

        win.attach(rt);
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
