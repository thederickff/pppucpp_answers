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
        fl_color(color * 3 / 2);
        i++;
      }

      fl_rectf(point(0).x, point(0).y + i, width(), 1);
    }
  }

  if (color().visibility()) {
    fl_rect(point(0).x, point(0).y, width(), height());
  }
}

///////////////////////////// Exercise 06 //////////////////////////////////////
Stripped_circle::Stripped_circle(Point p, int rr)
: r(rr)
{
  add(Point{ p.x - r, p.y - r });
}

void Stripped_circle::draw_lines() const
{
  if (fill_color().visibility())
  {
    for (int i = 90; i <= 270; ++i)
    {
      if (i % 2 == 0)
        fl_color(fill_color().as_int());
      else
        fl_color(fill_color().as_int() * 3 / 2);
      int y = abs(int(sin(radian(i)) * r) + point(0).y + r);
      int radius = abs(int(cos(radian(i)) * r));

      fl_rectf(point(0).x + r - radius, y, radius * 2, 2);
    }
  }

  if (color().visibility()) {
    fl_color(color().as_int());
    fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
  }
}

///////////////////////////// Exercise 07 //////////////////////////////////////
bool lie_on_line(Point p1, Point p2, Point current)
{
    int dxc = current.x - p1.x;
    int dyc = current.y - p1.y;

    int dx1 = p2.x - p1.x;
    int dy1 = p2.y - p1.y;

    int res = (dxc * dy1) - (dyc * dy1);

    if (res == 0)
    {
        if (abs(dx1) > abs(dy1)) {
            if (dx1 > 0) {
                return p1.x <= current.x && current.x <= p2.x;
            } else {
                return p2.x <= current.x && current.x <= p1.x;
            }            
        } else {
            if (dy1 > 0) {
                return p1.y <= current.y && current.y <= p2.y;
            } else {
                return p2.y <= current.y && current.y <= p1.y;
            }
        } 
    }

    return false;
}

bool line_segment_intersection(Point p1, Point p2, Point p3, Point p4, Point &intersect)
{
    double x1 = p1.x, y1 = p1.y;
    double x2 = p2.x, y2 = p2.y;
    double x3 = p3.x, y3 = p3.y;
    double x4 = p4.x, y4 = p4.y;
   
    double denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
	double u1 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
	double u2 = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);    

    if (denom == 0 && u1 != 0 && u2 != 0) {
        return false;
    }

    u1 = u1 / denom;
    u2 = u2 / denom;

    if (u1 < 0 || u1 > 1 || u2 < 0 || u2 > 1) {
        return false;
    }

    intersect.x = x1 + u1 * (x2 - x1);
    intersect.y = y1;

    return true;
}

Striped_closed_polyline::Striped_closed_polyline(int d): density(d)
{
}

void Striped_closed_polyline::draw_lines() const
{
    Closed_polyline::draw_lines();

    int min_x = point(0).x; // top left-most point's x
    int min_y = point(0).y; // top left-most point's y
    int max_x = point(0).x; // right-most point's x
    int max_y = point(0).y; // bottom point's y

    vector<Point> lines; // to hold lines

    // retrieve the four highest points
    for (int i = 1; i < number_of_points(); ++i)
    {
        if (point(i).x < min_x) min_x = point(i).x;
        if (point(i).y < min_y) min_y = point(i).y;
        if (point(i).x > max_x) max_x = point(i).x;
        if (point(i).y > max_y) max_y = point(i).y;
    }
    
    // retrieve intersections between horizontal lines (from left-most to right-most) and polylines, and polyline's last line
    for (int y = min_y + density; y < max_y; y += density)
    {
        Point intersect;
        
        for (int i = 1; i < number_of_points(); ++i)
        {
            if (line_segment_intersection(Point{min_x, y}, Point{max_x, y}, point(i-1), point(i), intersect))
            {
                lines.push_back(intersect); // find an intersection of polyline and horizontal lines
            }
        }

        if (line_segment_intersection(Point{min_x, y}, Point{max_x, y}, point(number_of_points()-1), point(0), intersect))
        {
            lines.push_back(intersect); // last line of polyline (starting in the last point and ending in the first one
        }
    }
    
    int index = 0;
    for (int i = 1; i < lines.size(); i += 2)
    {
        Line line {lines[i], lines[i-1]};

        if (index % 2 == 0) line.set_color(2);
        else line.set_color(5);

        line.draw();
        index++;
    }
}

///////////////////////////// Exercise 08 //////////////////////////////////////
Octagon::Octagon(Point p, int rr)
    : r(rr)
{
    int size = angcirc / 8;
    
    for (int i = 0; i < 360; i += size)
    {
        Point point {
            int(cos(radian(i)) * r) + p.x,
            abs(int(sin(radian(i)) * r) - p.y)
        };

        add(point);
    }
}

void Octagon::draw_lines() const
{
    Closed_polyline::draw_lines();
}

///////////////////////////// Exercise 09 //////////////////////////////////////
Group::Group()
{
}

Group::Group(initializer_list<Shape*> ss)
{
  for (Shape* s : ss)
  {
    add(s);
  }
}

Group::~Group()
{
}

void Group::add(Shape& shape)
{
  shapes.push_back(shape);
}

void Group::add(Shape* shape)
{
  shapes.push_back(shape);
}

void Group::attachTo(Simple_window& win)
{
  for (int i = 0; i < shapes.size(); ++i)
  {
    win.attach(shapes[i]);
  }
}

void Group::move(int dx, int dy)
{
  for (int i = 0; i < shapes.size(); ++i)
  {
    shapes[i].move(dx, dy);
  }
}

///////////////////////////// Exercise 10 //////////////////////////////////////
Pseudo_window::Pseudo_window(Point xy, int w, int h, const string& s)
: width(w), height(h), str(s), image(Point{xy.x + width / 3 , xy.y + height / 2 + 10}, "friend.jpg")
{
  if (w <= 0 || h <= 0)
    error("Bad box: non-positive side");

  add(xy);
}

void Pseudo_window::draw_lines() const
{
  if (color().visibility())
  {
    draw_border();
    draw_title();
    draw_content();
  }
}

void Pseudo_window::draw_border() const
{
    Point c1{point(0).x, point(0).y};
    Point c2{point(0).x + width, point(0).y};
    Point c3{point(0).x, point(0).y + height};
    Point c4{point(0).x + width, point(0).y + height};

    fl_arc(c1.x, c1.y, width, height, 90, 180);
    fl_arc(c2.x, c2.y, width, height, 0, 90);
    fl_arc(c3.x, c3.y, width, height, 180, 270);
    fl_arc(c4.x, c4.y, width, height, 270, 360);

    // Top left-right 
    fl_line(c1.x+width/2, c1.y, c2.x+width/2, c2.y);
    // Right top-bottom
    fl_line(c2.x+width, c2.y+height/2, c4.x+width, c4.y+height/2);
    // Left top-bottom
    fl_line(c1.x, c1.y+height/2, c3.x, c3.y+height/2);
    // Bottom legt-right
    fl_line(c3.x+width/2, c3.y+height, c4.x+width/2, c4.y+height);
}

void Pseudo_window::draw_title() const
{
  int yPos = point(0).y + height / 2;

  // title
  fl_draw(str.c_str(), point(0).x + width / 2, point(0).y + height / 4);
  fl_line(point(0).x, yPos, point(0).x+width*2, yPos);
  // control icons
  fl_arc(point(0).x + width / 5 + 10, point(0).y + height / 5, 10, 10, 0, 360);
  fl_arc(point(0).x + width / 5 + 24, point(0).y + height / 5, 10, 10, 0, 360);
  fl_arc(point(0).x + width / 5 + 38, point(0).y + height / 5, 10, 10, 0, 360);
}

void Pseudo_window::draw_content() const
{
  image.draw_lines();
}

///////////////////////////// Exercise 11 //////////////////////////////////////
Binary_tree::Binary_tree(Point xy, int level)
: m_Level(level)
{
  add(xy);
  constructNodes();
}

void Binary_tree::constructNodes()
{
  Point root = point(0);
  int offsetX = 0;
  int offsetY = 0;

  int offsetLevel = 0;
  int exp = 1;

  int parent_index = 0;
  bool flag = false;

  for (int i = 0; i < m_Level; ++i)
  {
    int size = m_Nodes.size();

    if (size == 0)
    {
      Shape* shape = newNode(root);
      shape->set_fill_color(Color::white);
      m_Nodes.push_back(shape);
      continue;
    }

    offsetY += 40;
  
    if (i > 1) {
      offsetLevel += exp-1;
      exp *= 2;
    }
  
    offsetX -= 15 * (i+offsetLevel);

    for (int j = 0; j <= size; ++j)
    {
      Shape* shape = newNode(Point{root.x + j * 30 + offsetX, root.y + offsetY});
      shape->set_fill_color(Color::white);
      m_Nodes.push_back(shape);
      
      if (instanceOf<Circle>(shape)) {
        Circle* child = dynamic_cast<Circle*>(shape);
        Circle* parent = dynamic_cast<Circle*>(&m_Nodes[parent_index]);
        
        m_Lines.push_back(new Line(parent->center(), child->center()));
      }
      
      if (flag) parent_index++;
      flag = !flag;
    }
  }
}

Shape* Binary_tree::newNode(Point xy)
{
  return new Circle(xy, 10);
}

void Binary_tree::draw_lines() const
{
  for (int i = 0; i < m_Lines.size(); ++i)
  {
    m_Lines[i].draw();
  }
  
  for (int i = 0; i < m_Nodes.size(); ++i)
  {
    m_Nodes[i].draw();
  }
}