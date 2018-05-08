/*
  A superellipse is a two-dimensional shape defined by the equation

                          |x|m  |y|n
                          |-| + |-|  = 1;   m,n > 0
                          |a|   |b|

  Look up superellipse on the web to get a better idea of what such shapes look
  like. Write a program that draws "starlike" patterns by connecting points on
  a superellipse. Take a, b, m, n and N as arguments. Select N points on the
  superellipse defined by a, b, m, and n. Make the points equally spaced for
  some definition of "equal". Connect each of those N points to one or more
  other points (if you like you can make the number of points to which to
  connect a point another argument or just use N-1, i.e., all the other points).
*/
#include "Simple_window.h"
#include "Graph.h"

constexpr int win_width = 800;
constexpr int win_height = 600;

int sign(double w)
{
  if (w > 0) return +1;
  if (w < 0) return -1;
  return 0;
}

void draw_superellipse(double a, double b, double m, double n, double sides, Polygon &poly, Simple_window &win);

int main()
{
  Point top_left{100, 100};
  Simple_window win(top_left, win_width, win_height, "Exercise #12");

  try
  {
    constexpr double a = 1;
    constexpr double b = 0.75;
    constexpr double m = 0.5;
    constexpr double n = 0.5;

    Polygon superellipse;
    int sides = 20;
    draw_superellipse(a, b, m, n, sides, superellipse, win);

    win.wait_for_button();
  }
  catch (const runtime_error &rte)
  {
    Text err_msg_start{ Point{150, 200}, "Runtime_error: "};
    Text err_msg{ Point{250, 200}, rte.what()};
    win.attach(err_msg_start);
    win.attach(err_msg);

    win.wait_for_button();
  }
  catch (const exception &e)
  {
    Text err_msg_start{ Point{150, 200}, "Exception: "};
    Text err_msg{ Point{250, 200}, e.what()};
    win.attach(err_msg_start);
    win.attach(err_msg);

    win.wait_for_button();
    return 2;
  }
  catch (...)
  {
    Text err_msg{ Point{150, 200}, "Unkown exception caught."};
    win.attach(err_msg);

    win.wait_for_button();
    return 1;
  }

  return 0;
}

void draw_superellipse(double a, double b, double m, double n, double sides, Polygon &poly, Simple_window &win)
{
  constexpr double pi = 3.14159265359;
  constexpr int angles = 360;
  constexpr double radius = 150;

  int offsetX = win_width / 2;
  int offsetY = -(win_height / 2);

  for (int deg = 0; deg < angles; deg += (angles / sides))
  {
    double rad = deg * pi / 180;
    double x = cos(rad);
    double y = sin(rad);

    x = pow(abs(x), 2/m) * a * sign(x);
    y = pow(abs(y), 2/n) * b * sign(y);

    int x_pos = int(radius * x) + offsetX;
    int y_pos = abs(int(radius * y) + offsetY);

    Point pt {x_pos, y_pos};
    poly.add(pt);

  }

  win.attach(poly);
}
