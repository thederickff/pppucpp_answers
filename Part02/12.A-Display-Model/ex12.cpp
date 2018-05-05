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

int main()
{
  Simple_window win(Point{300, 150}, 640, 480, "Exercise #12");

  

  win.wait_for_button();

  return 0;
}
