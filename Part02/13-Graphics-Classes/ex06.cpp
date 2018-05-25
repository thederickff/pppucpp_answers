/*
  Write a program that draws a class diagram like the one in §12.6. It will
  simplify matters if you start by defining a Box class that is a rectangle with
  a text label.
*/
#include "Custom_shapes.h"

int main()
{
  Simple_window win(Point{250, 10}, win_width, win_height, "Exercise 06 - Chapter 13: Graphics Classes");

  try
  {
    //Text text(Point{220, 225}, "Custom_shapes.h askdjasdkj");
    //Box box(Point{200, 200}, text.label().size() * 6, 20);
    Box_with_label window(Point{100, 100}, "Window");
    Box_with_label simple_window(Point{100, 200}, "Simple_window");
    Box_with_label line_style(Point{300, 100}, "Line_style");
    Box_with_label color(Point{500, 100}, "Color");
    Box_with_label shape(Point{330, 190}, "Shape");
    Box_with_label point(Point{530, 200}, "Point");

    Box_with_label line(Point{70, 300}, "Line");
    Box_with_label lines(Point{160, 300}, "Lines");
    Box_with_label polygon(Point{260, 300}, "Polygon");
    Box_with_label axis(Point{370, 300}, "Axis");
    Box_with_label rectangle(Point{460, 300}, "Rectangle");
    Box_with_label text(Point{580, 300}, "Text");
    Box_with_label image(Point{670, 300}, "Image");
    Arrow sw_w(Point{simple_window.point(0).x + simple_window.w() / 2, simple_window.point(0).y}, 50, 90);
    Arrow line_s(Point{line.point(0).x + line.w(), line.point(0).y}, 228, 18);
    Arrow lines_s(Point{lines.point(0).x + lines.w(), lines.point(0).y}, 150, 26);
    Arrow polygon_s(Point{polygon.point(0).x + polygon.w(), polygon.point(0).y}, 72, 58);
    Arrow axis_s(Point{axis.point(0).x + axis.w(), axis.point(0).y}, 74, 120);
    Arrow rectangle_s(Point{rectangle.point(0).x + rectangle.w(), rectangle.point(0).y}, 139, 151);
    Arrow text_s(Point{text.point(0).x + text.w(), text.point(0).y}, 213, 161);
    Arrow image_s(Point{image.point(0).x + image.w(), image.point(0).y}, 298, 164);


    //win.attach(box);
    //win.attach(text);
    win.attach(window);
    win.attach(simple_window);
    win.attach(line_style);
    win.attach(color);
    win.attach(shape);
    win.attach(point);
    win.attach(line);
    win.attach(lines);
    win.attach(polygon);
    win.attach(axis);
    win.attach(rectangle);
    win.attach(text);
    win.attach(image);

    win.attach(sw_w);
    win.attach(line_s);
    win.attach(lines_s);
    win.attach(polygon_s);
    win.attach(axis_s);
    win.attach(rectangle_s);
    win.attach(text_s);
    win.attach(image_s);

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
