/*
  Draw the color matrix from §13.10, but without lines around each color.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 20}, win_width, win_height, "Exercise 13 - Chapter 13: Graphics Classes");

  try
  {
    Vector_ref<Rectangle> rects;

    int size = 20;

    for (int i = 0; i < 16; ++i)
    {
      for (int j = 0; j < 16; ++j)
      {
        rects.push_back(new Rectangle(Point{i * size, j * size}, size, size));
        int last = rects.size() - 1;
        rects[last].set_fill_color(Color{i * 16 + j});
        rects[last].set_color(Color{i * 16 + j});
        win.attach(rects[last]);
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
