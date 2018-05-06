/*
  Draw a series of regular polygons, one inside the other. The innermost should
  be an equilateral triangle, enclosed by a square, enclosed by a pentagon, etc.
  For the mathematically adept only: let all the points of each N-polygon touch
  sides of the (N+1)-polygon. Hint: The trigonometric functions are found in
  <cmath> (§24.8, §B.9.2).
*/
#include "Simple_window.h"
#include "Graph.h"

#include <cmath>

void draw_poly(Simple_window &win, Polygon &poly,
    const int sides, const int win_width, const int win_height);

int main()
{

  Point top_left{100, 100};
  constexpr int win_width = 600;
  constexpr int win_height = 400;

  Simple_window win{ top_left, win_width, win_height, "Exercises #11" };

  try
  {
    Polygon tri;
    constexpr int tri_sides = 3;
    draw_poly(win, tri, tri_sides, win_width, win_height);

    Polygon quadr;
    constexpr int quadr_sides = 4;
    draw_poly(win, quadr, quadr_sides, win_width, win_height);

    Polygon penta;
    constexpr int penta_sides = 5;
    draw_poly(win, penta, penta_sides, win_width, win_height);

    Polygon hexa;
    constexpr int hexa_sides = 6;
    draw_poly(win, hexa, hexa_sides, win_width, win_height);

    Polygon septa;
    constexpr int septa_sides = 7;
    draw_poly(win, septa, septa_sides, win_width, win_height);

    Polygon octa;
    constexpr int octa_sides = 8;
    draw_poly(win, octa, octa_sides, win_width, win_height);

    Polygon nova;
    constexpr int nova_sides = 9;
    draw_poly(win, nova, nova_sides, win_width, win_height);

    Polygon deca;
    constexpr int deca_sides = 10;
    draw_poly(win, deca, deca_sides, win_width, win_height);


    win.wait_for_button();
  }
  catch (const runtime_error &rte)
  {
    Text err_msg_start{ Point{ 150, 200 }, "runtime_error: " };
    Text err_msg{ Point{ 250, 200 }, rte.what() };

    err_msg_start.set_color(Color::black);
    err_msg.set_color(Color::black);

    win.attach(err_msg_start);
    win.attach(err_msg);

    win.wait_for_button();
    return 1;
  }
  catch (const exception &e)
  {
    Text err_msg_start{ Point{ 150, 200 }, "Execption: " };
    Text err_msg{ Point{ 250, 200 }, e.what() };

    err_msg_start.set_color(Color::black);
    err_msg.set_color(Color::black);

    win.attach(err_msg_start);
    win.attach(err_msg);

    win.wait_for_button();
    return 2;
  }
  catch (...)
  {
    Text err_msg_start{ Point{ 150, 200 }, "An unknown execption occurred." };

    err_msg_start.set_color(Color::black);

    win.attach(err_msg_start);

    win.wait_for_button();

    return 3;
  }
  return 0;
}

void draw_poly(Simple_window &win, Polygon &poly,
    const int sides, const int win_width, const int win_height)
{
  constexpr double pi = 3.14159265359;
  constexpr int revolution = 360;
  constexpr double radius = 150;

  for (int deg = 0; deg < revolution; deg += (revolution / sides))
  {
    double rad = deg * pi / 180;
    Point pt {
      int(radius * cos(rad - pi / 2)) + (win_width / 2),
      abs(int(radius * sin(rad - pi / 2)) - (win_height / 2))
    };
    poly.add(pt);
    poly.set_color(Color::black);
  }

  win.attach(poly);
}
