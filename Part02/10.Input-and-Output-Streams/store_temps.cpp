/*
  Write a program that creates a file of data in the format of the temperature
  Reading type defined in §10.5. For testing, fill the file with at least 50
  "temperature readings". Call this program store_temps.cpp and the file it
  creates raw_temps.txt.
*/
#include "std_lib_facilities.h"

struct Reading {      //a temperature reading
  int hour;           //hour after midnight [0:23]
  double temperature;
  char scale;
};

int main()
{
  vector<Reading> temps {
    { 1,22.3, 'c'}, { 2,63.0, 'f'}, { 3, 22.9, 'c'}, { 4, 23.3, 'c'},
    { 5,62.6, 'f'}, { 6,13.5, 'c'}, { 7, 14.8, 'c'}, { 8, 64.7, 'f'},
    { 9,14.1, 'c'}, {10,65.5, 'f'}, {11, 67.4, 'f'}, {12, 18.9, 'c'},
    {13,22.3, 'c'}, {14,18.7, 'c'}, {15, 20.3, 'c'}, {16, 69.2, 'f'},
    {17,65.3, 'f'}, {18,18.6, 'c'}, {19, 15.9, 'c'}, {20, 66.3, 'f'},
    {21,22.3, 'c'}, {22,23.9, 'c'}, {23, 64.5, 'f'}, {24, 12.8, 'c'}
  };
  ofstream ofs {"raw_temps.txt"};

  for (int i = 0; i < temps.size(); ++i) {
    ofs << '(' << temps[i].hour << ',' << temps[i].temperature << " " << temps[i].scale << ")\n";
  }

  return 0;
}
