/*
  Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  Simple_window win({350, 110}, 640, 480, "Exercise #4");

  Rectangle rect1(Point{150, 100}, 100, 100);
  Rectangle rect2(Point{250, 100}, 100, 100);
  Rectangle rect3(Point{350, 100}, 100, 100);
  Rectangle rect4(Point{150, 200}, 100, 100);
  Rectangle rect5(Point{250, 200}, 100, 100);
  Rectangle rect6(Point{350, 200}, 100, 100);
  Rectangle rect7(Point{150, 300}, 100, 100);
  Rectangle rect8(Point{250, 300}, 100, 100);
  Rectangle rect9(Point{350, 300}, 100, 100);

  rect1.set_fill_color(Color::white);
  rect2.set_fill_color(Color::red);
  rect3.set_fill_color(Color::white);
  rect4.set_fill_color(Color::red);
  rect5.set_fill_color(Color::white);
  rect6.set_fill_color(Color::red);
  rect7.set_fill_color(Color::white);
  rect8.set_fill_color(Color::red);
  rect9.set_fill_color(Color::white);

  win.attach(rect1);
  win.attach(rect2);
  win.attach(rect3);
  win.attach(rect4);
  win.attach(rect5);
  win.attach(rect6);
  win.attach(rect7);
  win.attach(rect8);
  win.attach(rect9);

  win.wait_for_button();

  return 0;
}
