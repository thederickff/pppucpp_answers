#ifndef __Custom__Shapes__
#define __Custom__Shapes__

#include "Simple_window.h"
#include "Graph.h"

constexpr int win_width = 800;
constexpr int win_height = 600;

////////////////////////////////// Arc /////////////////////////////////////////
struct Arc : Shape
{
  Arc(Point p, int ww, int hh, int eaa); // center, width, height, end ang
  Arc(Point p, int ww, int hh, int iaa, int eaa); // center, width, height, init ang, end ang

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
  int ia;
  int ea;
};

////////////////////////////////// Box /////////////////////////////////////////
struct Box : Shape
{
  Box(Point p, int w, int h);

  void draw_lines() const;
private:
  int width;
  int height;
};

////////////////////////////////// Arrow ///////////////////////////////////////
constexpr double pi = 3.14159265359;

inline double radian(int angle)
{
  return angle * pi / 180;
}

inline int angleAdd(int a, int b)
{
  int angle = a + b;
  if (angle > 360) angle -= 360;
  return angle;
}
inline int angleSub(int a, int b)
{
  int angle = a - b;
  if (angle < 0) angle += 360;
  return angle;
}

struct Arrow : Shape
{
  Arrow(Point p1, int l, int a);
  void draw_lines() const;
private:
  int length;
  int angle;
};

/////////////////////////// Connection Points //////////////////////////////////
namespace cp {
  Point n(const Rectangle& r);
  Point s(const Rectangle& r);
  Point e(const Rectangle& r);
  Point w(const Rectangle& r);
  Point center(const Rectangle& r);
  Point ne(const Rectangle& r);
  Point se(const Rectangle& r);
  Point sw(const Rectangle& r);
  Point nw(const Rectangle& r);
}

#endif // defined(__Custom__Shapes__)
