/*
  Draw a 100-by-30 Rectangle and place the text "Howdy!" inside it/
*/
#include "Graph.h"
#include "Simple_window.h"

int main()
{
  try {

    Point tlc{350, 110};
    Simple_window win{tlc, 640, 480, "Exercise #2"};

    Rectangle rect(Point{270, 215}, 100, 30);
    Text text(Point{295, 235}, "Howdy!");

    win.attach(rect);
    win.attach(text);
    win.wait_for_button();

  } catch (exception& e) {
    cerr << e.what() << endl;
  } catch (...) {
    cerr << "Unknown exception caught." << endl;
  }
}
