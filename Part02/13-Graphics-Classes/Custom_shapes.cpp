#include "Custom_shapes.h"

////////////////////////////////// Arc /////////////////////////////////////////
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
