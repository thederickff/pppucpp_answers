/*
  Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
*/
#include "Simple_window.h"
#include "Graph.h"

struct Arc : Shape
{
public:
  Arc(Point p, int ww, int hh, int aa); // center, width, height, angle of arc

  void draw_lines() const;

  Point center() const;
  Point focus1() const;
  Point focus2() const;

  void set_major(int ww)
  {
    set_point(0, Point{center().x-ww, center().y-h});
    w = ww;
  }

  void set_minor(int hh)
  {
    set_point(0, Point{center().x-w, center().y-hh});
    h = hh;
  }

  int major() const { return w; }
  int minor() const { return h; }
private:
  int w;
  int h;
  int a;
};

Arc::Arc(Point p, int ww, int hh, int aa)
: w(ww), h(hh), a(aa)
{
  add(Point{p.x-w, p.y-h});
}

Point Arc::center() const
{
  return Point{point(0).x+w, point(0).y+h};
}

void Arc::draw_lines() const
{
  if (color().visibility())
    fl_arc(point(0).x, point(0).y, w, h, 0, a);
}

int main()
{
  constexpr int win_width = 800;
  constexpr int win_height = 600;

  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 01 - Chapter 13: Graphics Classes");

  try
  {
    Arc arc({500, 200}, 250, 150, 180);

    win.attach(arc);

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
