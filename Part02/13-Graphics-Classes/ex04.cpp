/*
  Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw().
  Each takes a Rectangle argument and returns a Point. These functions define
  "connection points" on and in the rectangle. For example, nw(r) is the
  northwest (top left) corner of a Rectangle r.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 04 - Chapter 13: Graphics Classes");

  try
  {
    Rectangle rect(Point{100,200}, 100, 100);
    Rectangle rect2(Point{300,200}, 100, 100);
    Rectangle rect3(Point{500,200}, 100, 100);

    Polygon poly;
    poly.add(cp::n(rect));
    poly.add(cp::se(rect));
    poly.add(cp::sw(rect));

    Polygon poly2;
    poly2.add(cp::s(rect2));
    poly2.add(cp::ne(rect2));
    poly2.add(cp::nw(rect2));

    Polygon poly3;
    poly3.add(cp::w(rect3));
    poly3.add(cp::center(rect3));
    poly3.add(cp::se(rect3));
    poly3.add(cp::e(rect3));
    poly3.add(cp::n(rect3));

    win.attach(rect);
    win.attach(poly);
    win.attach(rect2);
    win.attach(poly2);
    win.attach(rect3);
    win.attach(poly3);

    win.wait_for_button();
  }
  catch (const exception& e)
  {
    Text error_message(Point{150, 200}, "Exception caught: ");
    Text error_message_detail(Point{250, 200}, e.what());

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
