/*
  Write a program that reads the data from raw_temps.txt created in exercise 2
  into a vector and then calculates the mean and median temperatures in your
  data set. Call this program temp_stats.cpp.
*/
#include "std_lib_facilities.h"

struct Reading {
  int hour;
  double temperature;
  char scale;
};

ostream& operator<<(ostream& stream, const Reading& reading)
{
  stream << '(' << reading.hour << ',' << reading.temperature << " " << reading.scale << ")";
  return stream;
}

istream& operator>>(istream& stream, Reading& reading)
{
  int hour;
  double temperature;
  char ch1, ch2, ch3, scale;

  stream >> ch1 >> hour >> ch2 >> temperature >> scale >> ch3;

  if (!stream) return stream;
  if (ch1 != '(' || ch2 != ',' || ch3 != ')' || (scale != 'f' && scale != 'c')) { //ops: format error
    stream.clear(ios_base::failbit);
    return stream;
  }

  reading.hour = hour;
  reading.temperature = temperature;
  reading.scale = scale;

  return stream;
}

int main()
{
  vector<double> temps;

  ifstream ifs {"raw_temps.txt"};

  ifs.close();
  ifs.open("raw_temps.txt");
  while (!ifs.eof()) {
    Reading reading;
    ifs >> reading;
    if (reading.scale == 'c') {
      reading.temperature = ((reading.temperature * 9) / 5) + 32;
    }
    temps.push_back(reading.temperature);
  }

  double mean = 0, median = 0, mostRepeated = 0;
  sort(temps);
  cout << "-- SORT --\n";
  for (int i = 0; i < temps.size(); ++i) {
    cout << temps[i] << '\n';
    double repeats = 0;
    for (int j = i+1; j < temps.size(); ++j) {
        if (temps[i] == temps[j]) {
          repeats++;
        }
    }

    if (repeats > mostRepeated) {
      mostRepeated = repeats;
      mean = temps[i];
    }
  }

  if (temps.size() % 2 == 0) {
    median = (temps[temps.size() / 2] + temps[temps.size() / 2 + 1]) / 2;
  } else {
    median = temps[temps.size() / 2];
  }

  cout << "Mean: " << mean << '\n';
  cout << "Median: " << median << "\n";

  return 0;
}
