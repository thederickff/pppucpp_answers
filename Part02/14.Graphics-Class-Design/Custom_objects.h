#ifndef __Custom__Objects__
#define __Custom__Objects__

#include "Simple_window.h"
#include "Graph.h"

constexpr int win_width = 800;
constexpr int win_height = 600;

class Smiley : public Circle
{
public:
  Smiley(Point p, int rr);
  void draw_lines() const;

  int radius() const { return r; }

private:
  int r;
};

class Frowny : public Circle
{
public:
  Frowny(Point p, int rr);
  void draw_lines() const;

  int radius() const { return r; }

private:
  int r;
};

class SmileyWithHat : public Smiley
{
public:
  SmileyWithHat(Point p, int rr);
  void draw_lines() const;

  int radius() const { return r; }

private:
  int r;
};

class FrownyWithHat : public Frowny
{
public:
  FrownyWithHat(Point p, int rr);
  void draw_lines() const;

  int radius() const { return r; }

private:
  int r;
};


///////////////////////////// Exercise 04 //////////////////////////////////////
class Immobile_Circle : public Circle
{
public:
  Immobile_Circle(Point p, int r) : Circle(p, r) { }
  // void move(int dx, int dy) = delete
  void move(int dx, int dy) { /* do nothing */}
};

///////////////////////////// Exercise 05 //////////////////////////////////////
class Stripped_rectangle : public Rectangle
{
public:
  Stripped_rectangle(Point p, int w, int h);

  void draw_lines() const;
};

///////////////////////////// Exercise 06 //////////////////////////////////////
constexpr double pi = 3.14159265359;
constexpr int angcirc = 360;

inline double radian(int angle)
{
  return angle * pi / 180;
}

inline double angleAdd(double a, double b)
{
  double angle = a + b;
  if (angle > angcirc) angle -= angcirc;
  return angle;
}
inline double angleSub(double a, double b)
{
  double angle = a - b;
  if (angle < 0) angle += angcirc;
  return angle;
}


class Stripped_circle : public Shape
{
public:
  Stripped_circle(Point p, int rr);

  void draw_lines() const;

  inline int radius() const { return r; }
private:
  int r;
};

///////////////////////////// Exercise 07 //////////////////////////////////////
bool lie_on_line(Point p1, Point p2, Point current); // Checks if the point lies on the given line

bool line_segment_intersection(Point p1, Point p2, Point p3, Point p4, Point &intersect);

struct Striped_closed_polyline : Closed_polyline {
	Striped_closed_polyline(int d);
	void draw_lines() const;

private:
	int density;
};

///////////////////////////// Exercise 08 //////////////////////////////////////
class Octagon : public Closed_polyline
{
public:
  Octagon(Point p, int rr);
  void draw_lines() const;
    
  inline int radius() const { return r; }

private:
  int r;
};

///////////////////////////// Exercise 09 //////////////////////////////////////
class Group
{
public:
  Group();
  Group(initializer_list<Shape*> s);
  ~Group();
  Group(const Group &group) = delete;
  Group &operator=(const Group &group) = delete;

  void add(Shape& shape);
  void add(Shape* shape);

  void attachTo(Simple_window& win);

  void move(int dx, int dy);
private:
  Vector_ref<Shape> shapes; 
};

///////////////////////////// Exercise 10 //////////////////////////////////////
class Pseudo_window : public Shape
{
public:
  Pseudo_window(Point xy, int width, int height, const string& s);

  void draw_lines() const;
  int w() const { return width; }
  int h() const { return height; }
private:
  void draw_border() const;
  void draw_title() const;
  void draw_content() const;

  int width;
  int height;
  string str;
  Image image;
};

#endif // defined(__Custom__Objects__)
