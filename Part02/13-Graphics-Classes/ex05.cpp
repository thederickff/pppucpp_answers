/*
  Define the functions from exercise 4 for a Circle and an Ellipse. Place the
  connection points on or outside the shape but not outside the bounding
  rectangle.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 04 - Chapter 13: Graphics Classes");

  try
  {
    Circle circle(Point{200, 200}, 50);
    Ellipse ellipse(Point{400, 200}, 50, 80);

    Polygon inside;
    inside.add(cp::n(circle));
    inside.add(cp::e(circle));
    inside.add(cp::s(circle));
    inside.add(cp::w(circle));

    Polygon outside;
    outside.add(cp::nw(circle));
    outside.add(cp::ne(circle));
    outside.add(cp::sw(circle));
    outside.add(cp::se(circle));

    Polygon inside_e;
    inside_e.add(cp::n(ellipse));
    inside_e.add(cp::e(ellipse));
    inside_e.add(cp::s(ellipse));
    inside_e.add(cp::w(ellipse));

    Polygon outside_e;
    outside_e.add(cp::nw(ellipse));
    outside_e.add(cp::ne(ellipse));
    outside_e.add(cp::se(ellipse));
    outside_e.add(cp::sw(ellipse));

    win.attach(circle);
    win.attach(inside);
    win.attach(outside);
    win.attach(ellipse);
    win.attach(outside_e);
    win.attach(inside_e);

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
