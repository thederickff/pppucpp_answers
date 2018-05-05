/*
  Draw a series of regular polygons, one inside the other. The innermost should
  be an equilateral triangle, enclosed by a square, enclosed by a pentagon, etc.
  For the mathematically adept only: let all the points of each N-polygon touch
  sides of the (N+1)-polygon. Hint: The trigonometric functions are found in
  <cmath> (§24.8, §B.9.2).
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  Simple_window win(Point{350, 150}, 640, 480, "Exercise #11");

  int ix = win.x_max()/2, iy = win.y_max()/2;
  Polygon poly3;
  poly3.add(Point{ix, iy});
  poly3.add(Point{ix+10, iy});
  poly3.add(Point{ix+5, iy-10});

  Polygon poly4;
  poly4.add(Point{ix, iy});
  poly4.add(Point{ix+10, iy});
  poly4.add(Point{ix+10, iy-10});
  poly4.add(Point{ix, iy-10});

  Polygon poly5;
  poly5.add(Point{ix, iy});
  poly5.add(Point{ix+10, iy});
  poly5.add(Point{ix+10, iy-10});
  poly5.add(Point{ix+5, iy-20});
  poly5.add(Point{ix, iy-10});

  Polygon poly6;
  poly6.add(Point{ix, iy+5});
  poly6.add(Point{ix+10, iy+5});
  poly6.add(Point{ix+20, iy-10});
  poly6.add(Point{ix+10, iy-20});
  poly6.add(Point{ix, iy-25});
  poly6.add(Point{ix-10, iy-15});

  win.attach(poly3);
  win.attach(poly4);
  win.attach(poly5);
  win.attach(poly6);

  win.wait_for_button();


  return 0;
}
