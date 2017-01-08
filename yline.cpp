
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
double yLine::integrate(double a, double b) const{
  return (b-a);
};

// Overwrite y(s) and x(s)
double yLine::x(double s) const{
  return xC;			// Constant x for vertical line
};
double yLine::y(double s) const{
  return a+s*length;		// Simple formula for vertical line
};

// Curve parametrized in user coordinate
double yLine::xp(double p) const { return xC; }
double yLine::yp(double p) const { return p; }

// Derivatives w.r.t user parameter
double yLine::dxp(double p) const { return 0; }
double yLine::dyp(double p) const { return 1; }

