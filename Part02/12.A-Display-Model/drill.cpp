/*
  1. Get an emtpy Simple_window with the size 600 by 400 and a label My Window
     compiled, linked, and run. Note that you have to link the FLTK library as
     described in Appendix D. #include Graph.h and Simple_window.h in your code;
     and include Graph.cpp and Window.cpp in your project.
*/
#include "Simple_window.h" // get access to our window library
#include "Graph.h"         // get access to out graphics library facilities

#include <stdexcept>

int main()
{
  try {
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib

    Point tl {100, 100};        // to become top left corner of window

    Simple_window win {tl, 600, 400, "My window"}; // make simple window


    win.wait_for_button();  // give control to the display engine

  } catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
  } catch (...) {
    cerr << "Unknown error" << '\n';
    return 2;
  }

  return 0;
}
