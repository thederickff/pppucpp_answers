#ifndef __Custom__Shapes__
#define __Custom__Shapes__

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

#endif // defined(__Custom__Shapes__)
