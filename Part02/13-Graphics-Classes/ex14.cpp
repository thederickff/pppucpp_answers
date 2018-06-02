/*
  Define the right triangle class. Make an octagonal shape out of eight right
  triangles of different colors.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 40}, win_width, win_height, "Exercise 14 - Chapter 13: Graphics Classes");

  try
  {
    Vector_ref<Right_triangle> rts;

    int steps = angcirc / 8;
    int color = 0;
    int step_color = 255 / 8;
    Point center(300, 250);
    int distance = 56;
    for (int i = 0; i < angcirc; i += steps) {
      Point p {
        int(cos(radian(angleAdd(i, 22.5))) * distance) + center.x,
        abs(int(sin(radian(angleAdd(i, 22.5))) * distance) + center.y)
      };

      rts.push_back(new Right_triangle(p, 40, 40, angleAdd(i, 180)));
      Right_triangle& rt = rts[rts.size() - 1];
      rt.set_fill_color(Color{color});
      win.attach(rt);
      color += step_color;
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
