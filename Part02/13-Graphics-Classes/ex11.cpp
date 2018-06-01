/*
  Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a
  300-pixel-long y axis through the center of the ellipse. Mark the foci.
  Mark a point on the ellipse that is not on one of the axes. Draw the two
  lines from the fonci to the point.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 20}, win_width, win_height, "Exercise 11 - Chapter 13: Graphics Classes");

  try
  {
    Ellipse el(Point{380, 350}, 300, 200);
    Axis xa {Axis::x, Point{el.center().x, el.center().y}, 400, 10, "x"};
    Axis ya {Axis::y, Point{el.center().x, el.center().y}, 300, 10, "y"};

    Point f1 = el.focus1();
    Point f2 = el.focus2();
    Point out(el.center().x - el.major() / 2, el.center().y + el.minor() / 2);

    Marked_polyline mpl {"FOF"};
    mpl.add(f1);
    mpl.add(out);
    mpl.add(f2);

    win.attach(xa);
    win.attach(ya);
    win.attach(el);
    win.attach(mpl);
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
