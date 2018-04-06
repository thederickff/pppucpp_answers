/*
  Write a program that creates a file of data in the format of the temperature
  Reading type defined in §10.5. For testing, fill the file with at least 50
  "temperature readings". Call this program store_temps.cpp and the file it
  creates raw_temps.txt.
*/
#include "../std_lib_facilities.h"

struct Reading {      //a temperature reading
  int hour;           //hour after midnight [0:23]
  double temperature; //in fahrenheit
};

int main()
{
  vector<Reading> temps {
    { 1,62.3}, { 2,63.0}, { 3, 62.9}, { 4, 63.3},
    { 5,62.6}, { 6,63.5}, { 7, 64.8}, { 8, 64.7},
    { 9,64.1}, {10,65.5}, {11, 67.4}, {12, 68.9},
    {13,67.6}, {14,68.7}, {15, 70.3}, {16, 69.2},
    {17,65.3}, {18,68.6}, {19, 65.9}, {20, 66.3},
    {21,65.1}, {22,63.9}, {23, 64.5}, {24, 62.8}
  };
  ofstream ofs {"raw_temps.txt"};

  for (int i = 0; i < temps.size(); ++i) {
    ofs << '(' << temps[i].hour << ',' << temps[i].temperature << ")\n";
  }

  return 0;
}
