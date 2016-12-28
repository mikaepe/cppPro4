
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

// Overwrite integrate (arc length = interval length)
double yLine::integrate(double a, double b){
  return (b-a);
};

// Overwrite y(s) and x(s)
double yLine::x(double s){
  return xC;			// Constant x for vertical line
};
double yLine::y(double s){
  return a+s*length;		// Simple formula for vertical line
};

// Curve parametrized in user coordinate
double yLine::xp(double p) { return xC; }
double yLine::yp(double p) { return p; }

// Derivatives w.r.t user parameter
double yLine::dxp(double p) { return 0; }
double yLine::dyp(double p) { return 1; }

