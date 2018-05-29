/*
  Define a class Regular_hexagon (a regular hexagon is a six-sided polygon with
  all sides of equal length). Use the center and the distance from the center to
  a corner point as constructor arguments.
*/
int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 10 - Chapter 13: Graphics Classes");

  try
  {
    Regular_hexagon rh(Point{400, 310}, 60);
    rh.set_fill_color(Color::dark_red);
    win.attach(rh);
    win.wait_for_button();
  }
  catch (const exception& e)
  {
    Text error_message(Point{150, 200}, "Exception caught: ");
    Text error_message_detail(Point{280, 200}, e.what());

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
