/*
  Define a class Star. One parameter should be the number of points. Draw a few
  stars with differing numbers of points, differing line colors, and differing
  fill colors.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 40}, win_width, win_height, "Exercise 15 - Chapter 13: Graphics Classes");

  try
  {
    Vector_ref<Star> stars;

    int size = 50;
    int steps = size * 2;

    int y = 0;
    int x = 0;
    int num_points = 4;
    for (int i = size; i < win.x_max(); i += steps)
    {
      for (int j = size; j < win.y_max(); j += steps)
      {
        stars.push_back(new Star(Point{i, j}, num_points, 50));
        Star& star = stars[stars.size() - 1];

        if (x % 2 == 0) {
          if (y % 2 == 0) {
            star.set_fill_color(Color{y});
            star.set_color(Color{x});
          } else {
            star.set_fill_color(Color{y * 2});
            star.set_color(Color{x * 2});
          }
        } else {
          if (y % 2 == 0) {
            star.set_fill_color(Color{y * 3});
            star.set_color(Color{x * 3});
          } else {
            star.set_fill_color(Color{y * 4});
            star.set_color(Color{x * 4});
          }
        }

        if (y % 2 == 0) {
          num_points++;
        }

        if (num_points > 12) {
          num_points = 4;
        }

        win.attach(star);
        y++;
      }
      x++;
    }
    //Star star();

    //win.attach(star);
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
