/*
  What happens when you draw a Shape that doesn't fit inside its window? What
  happens when you draw a Window that doesn't fit on your screen? Write two
  programs that illustrate these two phenomena.
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  Simple_window ws{Point(350, 110), 640, 480, "Exercise #6.1 - A shape that doesn't fit inside this window"};
  Circle circle{Point(325, 250), 350};

  ws.attach(circle);
  ws.wait_for_button();
  /* One part or the whole part of the shape that doesn't fit inside its window, is not shown. */
  Simple_window ww{Point(350, 110), 4000, 2200, "Exercise #6.2 - A window that doesn't fit the screen"};
  ww.attach(circle);
  ww.wait_for_button();
  /* When the size of the window doesn't fit inside its screen, the content of the window is compressed to fit */
  return 0;
}
