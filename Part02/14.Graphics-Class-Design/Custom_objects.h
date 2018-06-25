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
class Stripped_circle : public Circle
{
public:
  Stripped_circle(Point p, int r);
};

#endif // defined(__Custom__Objects__)
