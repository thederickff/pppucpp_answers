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
  Simple_window win(Point{300, 150}, 640, 480, "Exercise #11");

  

  win.wait_for_button();

  return 0;
}
