/*
  1. Make an 800-by-1000 Simple_window.
  2. Put an 8-by-8 grid on the leftmost 800-by-800 part of the window (so that
     each square is 100 by 100).
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  constexpr int win_width = 800;
  constexpr int win_height = 1000;

  Simple_window win(Point{250, 10}, win_width, win_height, "Unnamed Objects");

  try
  {
    Vector_ref<Rectangle> rects;

    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        rects.push_back(new Rectangle(Point{i*100, j*100}, 100, 100));
        win.attach(rects[rects.size()-1]);
      }
    }

    win.wait_for_button();
  }
  catch (const exception& e)
  {
    Text error_message(Point{150, 200}, "Exception caught: ");
    Text error_message_detail(Point{250, 200}, e.what());

    win.attach(error_message);
    win.attach(error_message_detail);
    win.wait_for_button();
  }
  catch (...)
  {
    Text error_message(Point{150, 200}, "unknown_exception caught!");

    win.attach(error_message);
    win.wait_for_button();
  }


  return 0;
}
