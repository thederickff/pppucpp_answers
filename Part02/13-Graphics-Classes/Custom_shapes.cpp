#include "Custom_shapes.h"

////////////////////////////////// Arc /////////////////////////////////////////
Arc::Arc(Point p, int ww, int hh, int eaa)
: w(ww), h(hh), ia(0), ea(eaa)
{
  add(Point{p.x-w, p.y-h});
}

Arc::Arc(Point p, int ww, int hh, int iaa, int eaa)
: w(ww), h(hh), ia(iaa), ea(eaa)
{
  add(Point{p.x-w, p.y-h});
}

Point Arc::center() const
{
  return Point{point(0).x+w, point(0).y+h};
}

void Arc::draw_lines() const
{
  if (color().visibility()) {
    fl_arc(point(0).x, point(0).y, w, h, ia, ea);
    fl_line(point(0).x, point(0).y+w/2, point(0).x, point(0).y+w+20);
  }
}

////////////////////////////////// Box /////////////////////////////////////////
Box::Box(Point p, int w, int h)
: width(w), height(h)
{
  if (w <= 0 || h <= 0)
    error("Bad box: non-positive side");

  add(p);
}

void Box::draw_lines() const
{
  if (color().visibility())
  {
    Point c1{point(0).x, point(0).y};
    Point c2{point(0).x + width, point(0).y};
    Point c3{point(0).x, point(0).y + height};
    Point c4{point(0).x + width, point(0).y + height};

    fl_arc(c1.x, c1.y, width, height, 90, 180);
    fl_arc(c2.x, c2.y, width, height, 0, 90);
    fl_arc(c3.x, c3.y, width, height, 180, 270);
    fl_arc(c4.x, c4.y, width, height, 270, 360);

    fl_line(c1.x+width/2, c1.y, c2.x+width/2, c2.y);
    fl_line(c2.x+width, c2.y+height/2, c4.x+width, c4.y+height/2);
    fl_line(c1.x, c1.y+height/2, c3.x, c3.y+height/2);
    fl_line(c3.x+width/2, c3.y+height, c4.x+width/2, c4.y+height);

  }
}
