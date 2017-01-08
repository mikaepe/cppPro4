//file: yline.cpp

#include "curvebase.hpp"
#include "yline.hpp"

// Constructor
yLine::yLine(double y0, double y1, double x0) {
  a = y0;
  b = y1;
  xC = x0;
  length = y1 - y0;
}

// Destructor
yLine::~yLine() {}

// yline.cpp
