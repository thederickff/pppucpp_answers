#include "Custom_objects.h"

Smiley::Smiley(Point p, int rr) : Circle(p, rr), r(rr / 2) // radius of object on face
{
  set_fill_color(Color::yellow);
  add({point(0).x + r * 1.1, point(0).y + r * 2}); // mouth
  add({point(0).x + r / 2, point(0).y + r}); // left-eye
  add({point(0).x + r * 2.5, point(0).y + r}); // right-eye
  add({point(0).x + (r / 2) * 1.5, point(0).y + r * 1.2}); // left-eye's pupil
  add({point(0).x + (r * 2.5) * 1.1, point(0).y + r * 1.2}); // right-eye's pupil
}

void Smiley::draw_lines() const
{
  Circle::draw_lines();

  fl_color(color().as_int());
  fl_arc(point(1).x, point(1).y, r * 1.8, r, 180, 360);

  if (color().visibility()) {
    fl_arc(point(2).x, point(2).y, r, r, 0, 360);
    fl_arc(point(3).x, point(3).y, r, r, 0, 360);
    fl_arc(point(4).x, point(4).y, r / 2, r / 2, 0, 360);
    fl_arc(point(5).x, point(5).y, r / 2, r / 2, 0, 360);
  }
  if (fill_color().visibility()) {	// fill
    fl_color(Color::cyan);
    fl_pie(point(2).x, point(2).y, r, r, 0, 360);
    fl_pie(point(3).x, point(3).y, r, r, 0, 360);
    fl_color(Color::black);
    fl_pie(point(4).x, point(4).y, r / 2, r / 2, 0, 360);
    fl_pie(point(5).x, point(5).y, r / 2, r / 2, 0, 360);
  }
}

Frowny::Frowny(Point p, int rr) : Circle(p, rr), r(rr / 2) // radius of object on face
{
  set_fill_color(Color::yellow);
  add(Point{point(0).x + r * 1.1, point(0).y + r * 2.5}); // mouth
  add(Point{point(0).x + r / 2, point(0).y + r}); // left-eye
  add(Point{point(0).x + r * 2.5, point(0).y + r}); // right-eye
  add(Point{point(0).x + (r / 2) * 1.5, point(0).y + r * 1.2}); // left-eye's pupil
  add(Point{point(0).x + (r * 2.5) * 1.1, point(0).y + r * 1.2}); // right-eye's pupil
}

void Frowny::draw_lines() const
{
  Circle::draw_lines();

  fl_color(color().as_int());
  fl_arc(point(1).x, point(1).y, r * 1.8, r, 0, 180);

  if (color().visibility()) {
    fl_arc(point(2).x, point(2).y, r, r, 0, 360);
    fl_arc(point(3).x, point(3).y, r, r, 0, 360);
    fl_arc(point(4).x, point(4).y, r / 2, r / 2, 0, 360);
    fl_arc(point(5).x, point(5).y, r / 2, r / 2, 0, 360);
  }
  if (fill_color().visibility()) {	// fill
    fl_color(Color::cyan);
    fl_pie(point(2).x, point(2).y, r, r, 0, 360);
    fl_pie(point(3).x, point(3).y, r, r, 0, 360);
    fl_color(Color::black);
    fl_pie(point(4).x, point(4).y, r / 2, r / 2, 0, 360);
    fl_pie(point(5).x, point(5).y, r / 2, r / 2, 0, 360);
  }
}

SmileyWithHat::SmileyWithHat(Point p, int rr) : Smiley(p, rr), r(rr / 2)
{
  add(Point{point(0).x + r, point(0).y});
}

void SmileyWithHat::draw_lines() const
{
  Smiley::draw_lines();

  if (color().visibility()) {
    fl_arc(point(6).x, point(6).y, r * 2, r / 1.2, 0, 360);
  }

  if (fill_color().visibility()) { // fill
    fl_color(Color::dark_blue);
    fl_pie(point(6).x, point(6).y, r * 2, r / 1.2, 0, 360);
  }
}

FrownyWithHat::FrownyWithHat(Point p, int rr) : Frowny(p, rr), r(rr / 2)
{
  add(Point{point(0).x + r, point(0).y});
}

void FrownyWithHat::draw_lines() const
{
  Frowny::draw_lines();

  if (color().visibility()) { // fill
    fl_arc(point(6).x, point(6).y, r * 2, r / 1.2, 0, 360);
    fl_rect(point(6).x + r / 2, point(6).y - 30, r, 40);
  }

  if (fill_color().visibility()) { // fill
    fl_color(Color::dark_red);
    fl_pie(point(6).x, point(6).y, r * 2, r / 1.2, 0, 360);
    fl_rectf(point(6).x + r / 2, point(6).y - 30, r, 40);
  }
}

///////////////////////////// Exercise 05 //////////////////////////////////////
Stripped_rectangle::Stripped_rectangle(Point p, int w, int h)
: Rectangle(p, w, h)
{

}


void Stripped_rectangle::draw_lines() const
{
  if (fill_color().visibility()) {
    int h = height();
    int color = fill_color().as_int();
    for (int i = 0; i < h; ++i)
    {
      if (i % 2 == 0) {
        fl_color(color);
      } else {
        fl_color(color + i);
        i++;
      }

      fl_rectf(point(0).x, point(0).y + i, width(), 1);
    }
  }

  if (color().visibility()) {
    fl_rect(point(0).x, point(0).y, width(), height());
  }
}
