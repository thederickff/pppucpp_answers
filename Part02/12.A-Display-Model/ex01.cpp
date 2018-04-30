/*
  Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the
  Polygon red and the lines of the Rectangle blue.
*/
#include <stdexcept>

#include "Graph.h"
#include "Simple_window.h"


int main()
{
  try {
    Point tlc{300,100};
    Simple_window win{tlc, 640, 480, "Exercise #1"};

    Rectangle rect{Point(20, 30), 40, 40};
    rect.set_color(Color::blue);
    Polygon poly;
    poly.add(Point{120, 30});
    poly.add(Point{160, 30});
    poly.add(Point{160, 70});
    poly.add(Point{120, 70});
    poly.set_color(Color::red);

    win.attach(rect);
    win.attach(poly);

    win.wait_for_button();
  } catch (exception& e) {
    cerr << e.what() << '\n';
  } catch (...) {
    cerr << "Unknown exception caught.\n";
  }
  return 0;
}
