/*
  1. Get an emtpy Simple_window with the size 600 by 400 and a label My Window
     compiled, linked, and run. Note that you have to link the FLTK library as
     described in Appendix D. #include Graph.h and Simple_window.h in your code;
     and include Graph.cpp and Window.cpp in your project.
  2. Now add the examples from §12.7 one by one, testing between each added
     subsection example.
  3. Go through and make one minor change (e.g, in color, in location, or in
     number of points) to each of the subsection examples.
*/
#include "Simple_window.h" // get access to our window library
#include "Graph.h"         // get access to out graphics library facilities

#include <stdexcept>

int main()
{
  try {
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib

    Point tl {350, 110};        // to become top left corner of window

    Simple_window win {tl, 600, 400, "My window"}; // make simple window


    win.wait_for_button();  // display

    Axis xa {Axis::x, Point{20, 300}, 410, 10, "x axis"}; // make an Axis
                        // an Axis is a kind of Shape
                        // Axis::x means horizontal
                        // starting at (20, 300)
                        // 280 pixels long
                        // 10 "notches"
                        // label the axis "x axis"
    xa.set_color(Color::dark_blue);
    xa.label.set_color(Color::dark_red);
    win.attach(xa);       // attach xa to window, win
    win.set_label("Canvas #2"); // relabel the window
    win.wait_for_button();  // display!

    Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
    ya.set_color(Color::dark_blue);            // choose color
    ya.label.set_color(Color::dark_red);  // choose color for the text

    win.attach(ya);
    win.set_label("Canvas #3");
    win.wait_for_button();      // display!

    Function sine {sin, 0, 45, Point{20, 150}, 1000, 9, 20}; // sine curve
        // plot sin() in the range[0:100] with (0,0) at (20, 150)
        // using 1000 points; scale x values * 50, scale y values * 50
    win.attach(sine);
    win.set_label("Canvas #4");
    win.wait_for_button();

    sine.set_color(Color::dark_green);  // we changed our mind about sine's color

    Polygon poly; // a polygon; a Polygon is a kind of Shape
    poly.add(Point{200, 200});  // three points make a triangle
    poly.add(Point{350, 120});
    poly.add(Point{400, 200});

    poly.set_color(Color::yellow);
    poly.set_style(Line_style::dot);
    win.attach(poly);
    win.set_label("Canvas #5");
    win.wait_for_button();

    Rectangle r{Point{200, 200}, 200, 25};  // top left corner, width, height
    r.set_color(Color::yellow);
    win.attach(r);
    win.set_label("Canvas #6");
    win.wait_for_button();

    Closed_polyline poly_rect;
    poly_rect.add(Point{110, 85});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 120});
    poly_rect.add(Point{400, 85});
    poly_rect.set_color(Color::dark_green);
    win.attach(poly_rect);
    win.set_label("Canvas #6.1");
    win.wait_for_button();

    poly_rect.add(Point{300, 50});
    win.set_label("Canvas #6.2");
    win.wait_for_button();

    r.set_fill_color(Color::yellow);  // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Canvas #7");
    win.wait_for_button();

    Text t {Point{100, 350}, "H&ll0, Gr§ph!c§l w0rld!"};
    t.set_color(Color::dark_yellow);
    win.attach(t);
    win.set_label("Canvas #8");
    win.wait_for_button();

    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(20);
    win.set_label("Canvas #9");
    win.wait_for_button();

    Image ii {Point{500, 50}, "image.jpg"}; // 400*212-pixel jpg
    win.attach(ii);
    win.set_label("Canvas #10");
    win.wait_for_button();

    ii.move(50, 150);
    win.set_label("Canvas #11");
    win.wait_for_button();

    Circle c {Point{100, 200}, 50};
    c.set_color(Color::green);
    Ellipse e {Point{100, 200}, 75, 25};
    e.set_color(Color::red);
    Mark m {Point{100, 200}, 'x'};

    ostringstream oss;

    oss << "Screen size: " << x_max() << "*" << y_max()
        << "; Window size: " << win.x_max() << "*" << win.y_max();

    Text sizes {Point{100, 20}, oss.str()};
    sizes.set_color(Color::cyan);
    Image cal {Point{225, 225}, "snow_cpp.jpg"};  // 320*240-pixel gif
    cal.set_mask(Point{40, 40}, 200, 150);        // display center part of image
    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.set_label("Canvas #12");
    win.wait_for_button();
  } catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
  } catch (...) {
    cerr << "Unknown error" << '\n';
    return 2;
  }

  return 0;
}
