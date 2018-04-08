#include "std_lib_facilities.h"

const int not_a_reading = -7777;  //less than absolute zero
const int not_a_month = -1;

vector<string> month_input_tbl = {
  "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};
vector<string> month_print_tbl = {
  "January", "February", "March", "April", "May", "June", "July",
  "August", "September", "October", "November", "December"
};

struct Day {
  vector<double> hour {vector<double>(24, not_a_reading)};
};

struct Month {              //a month of temperature readings
  int month {not_a_month};  //[0:11] January is 0
  vector<Day> day {32};     //[1:31] one vector of reading per day
};

struct Year {               //a year of temperature readings, organized by month
  int year;                 //positive == A.D.
  vector<Month> month {12}; //[0:11] January is 0
};

struct Reading {
  int day;
  int hour;
  double temperature;
};

int month_to_int(string mm)
{
  for (int i = 0; i < 12; ++i) if (month_input_tbl[i] == mm) return i;
  return -1;
}

string int_to_month(int i)
{
    if (i < 0 || i > 11) error("bad month index");
    return month_print_tbl[i];
}

bool is_valid(const Reading& r);
void end_of_loop(istream& ist, char term, const string& message);
istream& operator>>(istream& is, Reading& r);
istream& operator>>(istream& is, Month& m);
istream& operator>>(istream& is, Year& y);
void print_year(ofstream& ofs, const Year& y);
ostream& operator<<(ostream& os, const Month& m);
ostream& operator<<(ostream& os, const Reading& r);

// read a temperature reading from is into r
// Check format but don't bother with data validity
istream& operator>>(istream& is, Reading& r)  // format ( 3 4 9.7 )
{
  char ch1;
  if (is >> ch1 && ch1 != '(') {  // could it be a Reading?
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  char ch2;
  int d;
  int h;
  double t;
  is >> d >> h >> t >> ch2;
  if (!is || ch2 != ')') error("bad reading"); // messed-up reading
  r.day = d;
  r.hour = h;
  r.temperature = t;
  return is;
}

// read a month from is into m
istream& operator>>(istream& is, Month& m)  // format: {month feb ...}
{
  char ch = 0;
  if (is >> ch && ch != '{') {
    is.unget();
    is.clear(ios_base::failbit);            // we failed to read a Month
    return is;
  }

  string month_marker;
  string mm;
  is >> month_marker >> mm;
  if (!is || month_marker != "month") error("bad start of month");
  m.month = month_to_int(mm);
  int duplicates = 0;
  int invalids = 0;

  for (Reading r; is >> r; ) {
    if (is_valid(r)) {
      if (m.day[r.day].hour[r.hour] != not_a_reading)
        ++duplicates;
      m.day[r.day].hour[r.hour] = r.temperature;
    }
    else
      ++invalids;
  }

  if (invalids) error("invalid readings in month ", invalids);
  if (duplicates) error("duplicate readings in month ", duplicates);
  end_of_loop(is, '}', "bad end of month");
  return is;
}

// read from is into y
istream& operator>>(istream& is, Year& y) // format: { year 1972 ...}
{
  char ch;
  is >> ch;
  if (ch != '{') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  string year_marker;
  int yy;
  is >> year_marker >> yy;
  if (!is || year_marker != "year") error("bad start of year");
  y.year = yy;

  while (true) {
    Month m;      // get a clean m each time around
    if (!(is >> m)) break;
    y.month[m.month] = m;
  }

  end_of_loop(is, '}', "bad end of year");
  return is;
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

// a rough test
bool is_valid(const Reading& r)
{
  if (r.day < 1 || r.day > 31) return false;
  if (r.hour < 0 || r.hour > 23) return false;
  if (r.temperature < implausible_min || r.temperature > implausible_max)
    return false;
  return true;
}

void end_of_loop(istream& ist, char term, const string& message)
{
  if (ist.fail()) { // use term as terminator and/or separator
    ist.clear();
    char ch;
    if (ist >> ch && ch == term) return;  //all is fine
    error(message);
  }
}

int main()
{
  // open input file:
  cout << "Please enter input file name\n";
  string iname;
  cin >> iname;
  ifstream ifs {iname};
  if (!ifs) error("can't open input file ", iname);

  //ifs.exceptions(ifs.exceptions()|ios_base::badbit);  // throw for bad()

  // open output file:
  cout << "Please enter output file name\n";
  string oname;
  cin >> oname;
  ofstream ofs {oname};
  if (!ofs) error("can't open output file ", oname);

  // read an arbitrary number of years:
  vector<Year> ys;

  while (true) {
    Year y;       // get a freshly initialized Year each time around
    if (!(ifs >> y)) break;
    ys.push_back(y);
  }

  cout << "read " << ys.size() << " years of readings\n";

  for (const Year& y : ys) print_year(ofs, y);

  return 0;
}

void print_year(ofstream& ofs, const Year& y)
{

}
