/*
  Find a way to add color to the lines from the previous exercise. Make some
  lines one color and other lines another color or other colors.
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

void draw_superellipse(int start, int end, Open_polyline &poly, Simple_window &win);

int main()
{
  Point top_left{100, 100};
  Simple_window win(top_left, win_width, win_height, "Exercise #12");

  try
  {

    Open_polyline s1;
    s1.set_color(Color::dark_blue);
    draw_superellipse(0, 90, s1, win);
    Open_polyline s2;
    s2.set_color(Color::dark_red);
    draw_superellipse(90, 180, s2, win);
    Open_polyline s3;
    s3.set_color(Color::dark_magenta);
    draw_superellipse(180, 270, s3, win);
    Open_polyline s4;
    s1.set_color(Color::dark_green);
    draw_superellipse(270, 360, s4, win);

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

void draw_superellipse(int start, int end, Open_polyline &poly, Simple_window &win)
{
  constexpr double pi = 3.14159265359;
  constexpr double radius = 150;
  constexpr double a = 1;
  constexpr double b = 0.75;
  constexpr double m = 0.6;
  constexpr double n = 0.6;

  int offsetX = win_width / 2;
  int offsetY = -(win_height / 2);

  for (int deg = start; deg < end; deg++)
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
