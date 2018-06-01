/*
  Draw a circle. Move a mark around on the circle (let it move a bit each time
  you hit the "Next" button).
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 20}, win_width, win_height, "Exercise 11 - Chapter 13: Graphics Classes");

  try
  {
    Circle circle(Point{200, 250}, 100);

    int x = circle.point(0).x;
    int y = circle.center().y;
    int step = 20;

    win.attach(circle);

    while (true)
    {
      Mark mark(Point{x, y}, 'x');
      win.attach(mark);
      win.wait_for_button();
      x += step;
      if (x > (circle.center().x - circle.point(0).x) * 3) break;
    }
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
