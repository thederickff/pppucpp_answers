/*
  1. Start a program to work with points, discussed in §10.4. Begin by defining
     the data type Point that has two coordinate members x and y.
  2. Using the code and discussion in §10.4, prompt the user to input seven
     (x,y) pairs. As the data entered, store it in a vector of Points called
     original_points to see what it looks like.
*/
#include "../std_lib_facilities.h"

struct Point {
  int x, y;
};

int main()
{
  vector<Point> original_points;
  cout << "Input seven coordinates in the format (x,y).\n";
  for (int i = 0; i < 7; ++i) {
    cout << "#" << (i+1) << ": ";
    char ch1, ch2, ch3;
    int x, y;
    cin >> ch1 >> x >> ch2 >> y >> ch3;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
      cin.clear(ios_base::failbit);
      break;
    }
    Point point;
    point.x = x;
    point.y = y;
    original_points.push_back(point);
  }

  for (const Point& point : original_points) {
    cout << '(' << point.x << ',' << point.y << ')';
  }
  cout << '\n';

  return 0;
}
