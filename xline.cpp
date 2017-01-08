
#include "curvebase.hpp"
#include "xline.hpp"

// Constructor
xLine::xLine(double xi, double xf, double y0) {
  a = xi;
  b = xf;
  yConst = y0;
  length = xf-xi;
}

// Destructor
xLine::~xLine() {};

// Overwrite integrate (arc length = interval length)
double xLine::integrate(double a, double b) const{
  return (b-a);			
};

// Overwrite y(s) and x(s) in normalized coordinates
double xLine::y(double s) const{
    return yConst;		// Constant y for a horizontal line
};
double xLine::x(double s) const{
    return a+s*length;		// Simple formula for horizontal line
};

// Curve parametrized by user parameter
double xLine::xp(double p) const { return p; }
double xLine::yp(double p) const { return yConst; }

// Derivatives w.r.t. user parameter
double xLine::dxp(double p) const { return 1; }
double xLine::dyp(double p) const {return 0; }

