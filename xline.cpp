
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
double xLine::integrate(double a, double b){
  return (b-a);			
};

// Overwrite y(s) and x(s) in normalized coordinates
double xLine::y(double s){	
    return yConst;		// Constant y for a horizontal line
};
double xLine::x(double s){	
    return a+s*length;		// Simple formula for horizontal line
};

// Curve parametrized by user parameter
double xLine::xp(double p) { return p; }
double xLine::yp(double p) { return yConst; }

// Derivatives w.r.t. user parameter
double xLine::dxp(double p) { return 1; }
double xLine::dyp(double p) {return 0; }

