/*
  Draw the file diagram from §12.8.
*/
#include "Simple_window.h"
#include "Graph.h"

struct Vertex2 {
  int x;
  int y;
};

enum class Direction {
  left, right, up
};

class IncludeLine {
public:
  IncludeLine(Vertex2 includer, Vertex2 included);
  void draw(Simple_window &win, Direction dir);
private:
  Vertex2 m_includer;
  Vertex2 m_included;
  Polygon m_poly;
  Open_polyline m_line;
};

IncludeLine::IncludeLine(Vertex2 includer, Vertex2 included)
: m_includer(includer), m_included(included)
{

}

void IncludeLine::draw(Simple_window& win, Direction dir)
{
  switch(dir) {
    case Direction::left:
      m_poly.add(Point{m_included.x + 10, m_included.y+5});
      m_poly.add(Point{m_included.x + 10, m_included.y-3});
      m_poly.add(Point{m_included.x, m_included.y});
      break;
    case Direction::right:
      m_poly.add(Point{m_included.x - 8, m_included.y+12});
      m_poly.add(Point{m_included.x - 12, m_included.y+4});
      m_poly.add(Point{m_included.x, m_included.y});
      break;
    default:
      m_poly.add(Point{m_included.x - 4, m_included.y+10});
      m_poly.add(Point{m_included.x + 4, m_included.y+10});
      m_poly.add(Point{m_included.x, m_included.y});
      break;
  }
  m_poly.set_fill_color(Color::black);

  m_line.add(Point{m_includer.x, m_includer.y});
  m_line.add(Point{m_included.x, m_included.y});

  win.attach(m_poly);
  win.attach(m_line);
}

int main()
{
  Simple_window win(Point{300, 150}, 640, 480, "Exercise #10");

  Rectangle rect_background(Point{0, 22}, win.x_max(), win.y_max()-22);
  rect_background.set_fill_color(Color::white);
  win.attach(rect_background);

  int pix = 50, piy = 50;
  Rectangle rect_point_h(Point{pix, piy}, 150, 30);
  rect_point_h.set_fill_color(Color::yellow);
  Text text_point_h(Point{pix+10, piy+rect_point_h.height()/2+4}, "struct Point { ... };");
  Text title_point_h(Point{pix, piy-5}, "Point.h:");

  int gix = 50, giy = 150;
  Rectangle rect_graph_h(Point{gix, giy}, 160, 60);
  rect_graph_h.set_fill_color(Color::yellow);
  Text comment_graph_h(Point{gix+10, giy+rect_point_h.height()/2+4}, "// graphing interface:");
  Text text_graph_h(Point{gix+10, giy+rect_point_h.height()/2+24}, "struct Shape { ... };");
  Text dots_graph_h(Point{gix+10, giy+rect_point_h.height()/2+34}, "...");
  Text title_graph_h(Point{gix, giy-5}, "Graph.h:");

  IncludeLine graph_h_to_point_h({gix+rect_graph_h.width()/2, giy}, {pix+rect_graph_h.width()/2, piy+rect_point_h.height()});
  graph_h_to_point_h.draw(win, Direction::up);


  int igix = 10, igiy = 270;
  Rectangle rect_graph_cpp(Point{igix, igiy}, 100, 30);
  rect_graph_cpp.set_fill_color(Color::yellow);
  Text title_graph_cpp(Point{igix, igiy-5}, "Graph.cpp:");
  Text text_graph_cpp(Point{igix+10, igiy+rect_graph_cpp.height()/2+4}, "Graph code");

  IncludeLine graph_cpp_to_graph_h({igix+rect_graph_cpp.width()-15, igiy}, {gix+rect_graph_cpp.width()/2, giy+rect_graph_h.height()});
  graph_cpp_to_graph_h.draw(win, Direction::up);

  int cix = 80, ciy = 390;
  Rectangle rect_chapter_cpp(Point{cix, ciy}, 210, 60);
  rect_chapter_cpp.set_fill_color(Color::yellow);
  Text title_chapter_cpp(Point{cix, ciy-5}, "chapter12.cpp:");
  Text text1_chapter_cpp(Point{cix+10, ciy+rect_graph_cpp.height()/2+2}, "#include \"Graph.h\"");
  Text text2_chapter_cpp(Point{cix+10, ciy+rect_graph_cpp.height()/2+20}, "#include \"Simple_window.h\"");
  Text text3_chapter_cpp(Point{cix+10, ciy+rect_graph_cpp.height()/2+38}, "int main() { ... }");

  IncludeLine chapter_cpp_to_graph_h({cix+rect_chapter_cpp.width()/2+5, ciy}, {gix+rect_graph_h.width()/2+35, giy+rect_graph_h.height()});
  chapter_cpp_to_graph_h.draw(win, Direction::up);

  int wix = 270, wiy = 125;
  Rectangle rect_window_h(Point{wix, wiy}, 180, 60);
  rect_window_h.set_fill_color(Color::yellow);
  Text comment_window_h(Point{wix+10, wiy+rect_window_h.height()/2-10}, "// window interface:");
  Text text_window_h(Point{wix+10, wiy+rect_window_h.height()/2+6}, "class Window { ... };");
  Text dots_window_h(Point{wix+10, wiy+rect_window_h.height()/2+20}, "...");
  Text title_window_h(Point{wix, wiy-5}, "Window.h:");

  IncludeLine window_h_to_point_h({wix+10, wiy}, {pix+rect_point_h.width()/2+35, piy+rect_point_h.height()});
  window_h_to_point_h.draw(win, Direction::left);

  int iwix = 200, iwiy = 230;
  Rectangle rect_window_cpp(Point{iwix, iwiy}, 120, 30);
  rect_window_cpp.set_fill_color(Color::yellow);
  Text title_window_cpp(Point{iwix, iwiy-5}, "window.cpp:");
  Text text_window_cpp(Point{iwix+10, iwiy+rect_window_cpp.height()/2+4}, "Window code");

  IncludeLine window_cpp_to_window_h({iwix+rect_window_cpp.width()-25, iwiy}, {wix+rect_window_h.width()/2-20, wiy+rect_window_h.height()});
  window_cpp_to_window_h.draw(win, Direction::right);

  int swix = 220, swiy = 310;
  Rectangle rect_simple_window_h(Point{swix, swiy}, 200, 60);
  rect_simple_window_h.set_fill_color(Color::yellow);
  Text comment_simple_window_h(Point{swix+10, swiy+rect_simple_window_h.height()/2-10}, "// window interface:");
  Text text_simple_window_h(Point{swix+10, swiy+rect_simple_window_h.height()/2+6}, "class Simple_Window { ... };");
  Text dots_simple_window_h(Point{swix+10, swiy+rect_simple_window_h.height()/2+20}, "...");
  Text title_simple_window_h(Point{swix, swiy-5}, "Simple_window.h:");

  IncludeLine simple_window_h_to_window_h({swix+rect_simple_window_h.width()/2+40, swiy}, {wix+rect_window_h.width()/2, wiy+rect_window_h.height()});
  simple_window_h_to_window_h.draw(win, Direction::up);

  IncludeLine chapter_cpp_to_simple_window_h({cix+rect_chapter_cpp.width()/2+5, ciy}, {swix+35, swiy+rect_simple_window_h.height()});
  chapter_cpp_to_simple_window_h.draw(win, Direction::left);

  int guix = 420, guiy = 210;
  Rectangle rect_gui_h(Point{guix, guiy}, 150, 60);
  rect_gui_h.set_fill_color(Color::yellow);
  Text comment_gui_h(Point{guix+10, guiy+rect_gui_h.height()/2-10}, "// GUI interface:");
  Text text_gui_h(Point{guix+10, guiy+rect_gui_h.height()/2+6}, "struct In_box { ... };");
  Text dots_gui_h(Point{guix+10, guiy+rect_gui_h.height()/2+20}, "...");
  Text title_gui_h(Point{guix, guiy-5}, "GUI.h:");

  IncludeLine gui_h_to_window_h({guix+rect_gui_h.width()/2+5, guiy}, {wix+rect_window_h.width()-10, wiy+rect_window_h.height()});
  gui_h_to_window_h.draw(win, Direction::left);

  IncludeLine simple_window_h_to_gui_h({swix+rect_simple_window_h.width()/2+40, swiy}, {guix+10, guiy+rect_gui_h.height()});
  simple_window_h_to_gui_h.draw(win, Direction::right);

  int iguix = 430, iguiy = 340;
  Rectangle rect_gui_cpp(Point{iguix, iguiy}, 90, 30);
  rect_gui_cpp.set_fill_color(Color::yellow);
  Text title_gui_cpp(Point{iguix, iguiy-5}, "GUI.cpp:");
  Text text_gui_cpp(Point{iguix+10, iguiy+rect_gui_cpp.height()/2+4}, "GUI code");

  IncludeLine gui_cpp_to_gui_h({iguix+rect_gui_cpp.width()/2+25, iguiy}, {guix+rect_gui_h.width()/2, guiy+rect_gui_h.height()});
  gui_cpp_to_gui_h.draw(win, Direction::up);

  /* FLTK Headers */
  int fix = 300, fiy = 25;
  Rectangle rect_fltk_hs1(Point{fix, fiy}, 120, 35);
  rect_fltk_hs1.set_fill_color(Color::yellow);
  Rectangle rect_fltk_hs2(Point{fix+5, fiy+5}, 120, 35);
  rect_fltk_hs2.set_fill_color(Color::yellow);
  Rectangle rect_fltk_hs3(Point{fix+10, fiy+10}, 120, 35);
  rect_fltk_hs3.set_fill_color(Color::yellow);
  Text text_fltk_hs3(Point{fix+20, fiy+25}, "FLTK headers");

  IncludeLine graph_h_to_fltk_hs3({gix+rect_graph_h.width()/2, giy}, {fix+20, fiy+rect_fltk_hs3.height()+10});
  graph_h_to_fltk_hs3.draw(win, Direction::right);

  IncludeLine window_h_to_fltk_hs3({wix+rect_window_h.width()/2, wiy}, {fix+rect_fltk_hs3.width()/2, fiy+rect_fltk_hs3.height()+10});
  window_h_to_fltk_hs3.draw(win, Direction::up);

  IncludeLine gui_h_to_fltk_hs3({guix+rect_gui_h.width()/2+5, guiy}, {fix+rect_fltk_hs3.width()+8, fiy+rect_fltk_hs3.height()+10});
  gui_h_to_fltk_hs3.draw(win, Direction::up);

  /* FLTK Headers */
  int ifix = 500, ifiy = 55;
  Rectangle rect_fltk_cs1(Point{ifix, ifiy}, 100, 35);
  rect_fltk_cs1.set_fill_color(Color::yellow);
  Rectangle rect_fltk_cs2(Point{ifix+5, ifiy+5}, 100, 35);
  rect_fltk_cs2.set_fill_color(Color::yellow);
  Rectangle rect_fltk_cs3(Point{ifix+10, ifiy+10}, 100, 35);
  rect_fltk_cs3.set_fill_color(Color::yellow);
  Text text_fltk_cs3(Point{ifix+20, ifiy+25}, "FLTK code");

  IncludeLine fltk_cs1_to_fltk_hs3({ifix, ifiy+15}, {fix+rect_fltk_hs3.width()+10, fiy+rect_fltk_hs3.height()-5});
  fltk_cs1_to_fltk_hs3.draw(win, Direction::left);

  // Point.h
  win.attach(rect_point_h);
  win.attach(text_point_h);
  win.attach(title_point_h);

  // Graph.h
  win.attach(rect_graph_h);
  win.attach(text_graph_h);
  win.attach(comment_graph_h);
  win.attach(dots_graph_h);
  win.attach(title_graph_h);

  // Graph.cpp
  win.attach(rect_graph_cpp);
  win.attach(title_graph_cpp);
  win.attach(text_graph_cpp);

  // chapter12.cpp
  win.attach(rect_chapter_cpp);
  win.attach(title_chapter_cpp);
  win.attach(text1_chapter_cpp);
  win.attach(text2_chapter_cpp);
  win.attach(text3_chapter_cpp);

  // Window.h
  win.attach(rect_window_h);
  win.attach(text_window_h);
  win.attach(comment_window_h);
  win.attach(dots_window_h);
  win.attach(title_window_h);

  // Window.cpp
  win.attach(rect_window_cpp);
  win.attach(title_window_cpp);
  win.attach(text_window_cpp);

  // Simple_window.h
  win.attach(rect_simple_window_h);
  win.attach(text_simple_window_h);
  win.attach(comment_simple_window_h);
  win.attach(dots_simple_window_h);
  win.attach(title_simple_window_h);

  // GUI.h
  win.attach(rect_gui_h);
  win.attach(text_gui_h);
  win.attach(comment_gui_h);
  win.attach(dots_gui_h);
  win.attach(title_gui_h);

  // GUI.cpp
  win.attach(rect_gui_cpp);
  win.attach(title_gui_cpp);
  win.attach(text_gui_cpp);

  // FLTK headers
  win.attach(rect_fltk_hs1);
  win.attach(rect_fltk_hs2);
  win.attach(rect_fltk_hs3);
  win.attach(text_fltk_hs3);

  // FLTK code
  win.attach(rect_fltk_cs1);
  win.attach(rect_fltk_cs2);
  win.attach(rect_fltk_cs3);
  win.attach(text_fltk_cs3);

  win.wait_for_button();

  return 0;
}
