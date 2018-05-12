#include "Simple_window.h"
#include "Graph.h"

int main()
{
  constexpr int win_width = 800;
  constexpr int win_height = win_width * 9 / 12;

  Simple_window win(Point{250, 100}, win_width, win_height, "Unnamed Objects");

  try
  {
    Vector_ref<Rectangle> ref;

    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 16; ++j) {
        ref.push_back(new Rectangle(Point{i*30, j*30}, 30, 30));
        ref[ref.size()-1].set_fill_color(Color{j+16*i});
        win.attach(ref[ref.size()-1]);
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
