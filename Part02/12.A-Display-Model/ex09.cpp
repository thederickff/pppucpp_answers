/*
  Display an image on the screen, e.g., a photo of a friend. Label the image
  both with a title on the window and with a caption in the window.
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  Simple_window win(Point{300, 150}, 640, 480, "Exercise #9 - Show a Photo of a friend");

  Image ifriend(Point{200, 100}, "friend.jpg");
  Text caption{Point{200, 380}, "Image of a friend."};
  //Text t {Point{100, 350}, "H&ll0, Gr§ph!c§l w0rld!"};
  //t.set_color(Color::dark_yellow);
  //win.attach(t);
  //t.set_color(Color::dark_yellow);
  win.attach(ifriend);
  win.attach(caption);
  win.wait_for_button();

  return 0;
}
