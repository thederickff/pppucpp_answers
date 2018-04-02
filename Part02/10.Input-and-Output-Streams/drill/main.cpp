/*
  1. Start a program to work with points, discussed in §10.4. Begin by defining
     the data type Point that has two coordinate members x and y.
  2. Using the code and discussion in §10.4, prompt the user to input seven
     (x,y) pairs. As the data entered, store it in a vector of Points called
     original_points.
  3. Print the data in original_points to see what it looks like.
  4. Open an ofstream and output each point to a file named mydata.txt. On
     windows, we suggest the .txt suffix to makeit easier to look at the data
     with an ordinary text editor (such as wordpad).
  5. Close the ofstream and then open an ifstream for my data.txt. Read the data
     from mydata.txt and store it in a new vector called processed_points.
  6. Print the data elements of both vectors.
  7. Compare two vectors and print Something's wrong! if the number of elements
     or the values of elements differ.
*/
#include "../std_lib_facilities.h"

struct Point {
  int x, y;
};
ostream& operator<<(ostream& stream, const Point& point)
{
  stream << '(' << point.x << ',' << point.y << ')';
  return stream;
}
istream& operator>>(istream& stream, Point& point)
{
  char ch1, ch2, ch3;
  int x, y;
  stream >> ch1 >> x >> ch2 >> y >> ch3;
  if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
    stream.unget();
    stream.clear(ios::failbit);
    return stream;
  }
  if (!stream) error("failed to read Point");
  point.x = x;
  point.y = y;
  return stream;
}
bool operator==(const Point& a, const Point& b)
{
  return a.x == b.x && a.y == b.y;
}
bool operator!=(const Point& a, const Point& b)
{
  return !(a == b);
}

int main()
{
  vector<Point> original_points;
  vector<Point> processed_points;
  cout << "Input seven coordinates in the format (x,y).\n";
  for (int i = 0; i < 7; ++i) {
    cout << "#" << (i+1) << ": ";
    Point point;
    cin >> point;
    original_points.push_back(point);
  }
  ofstream ost {"mydata.txt"};

  for (const Point& point : original_points) {
    ost << point;
  }
  ost.close();
  ifstream ist {"mydata.txt"};
  for (Point point; ist >> point; ) {
    processed_points.push_back(point);
  }
  cout << "Original Points: ";
  for (const Point& point : original_points) {
    cout << point;
  }
  cout << '\n';
  cout << "Processed Points: ";
  for (const Point& point : processed_points) {
    cout << point;
  }
  cout << '\n';

  if (processed_points.size() != original_points.size()) {
    cout << "Something's wrong!\n";
  }
  for (int i = 0; i < processed_points.size(); ++i) {
    if (processed_points[i] != original_points[i]) {
      cout << "Something's wrong!\n";
    }
  }

  return 0;
}
