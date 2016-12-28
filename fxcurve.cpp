
#include <cmath>	// for exp in xp, yp, dxp, dyp

#include "curvebase.hpp"
#include "fxcurve.hpp"

// Constructor
fxCurve::fxCurve(double xx0, double xx1) {
  a = xx0;
  b = xx1;
  length = integrate(a,b);
}

// Destructor
fxCurve::~fxCurve() {}

// Curve parametrized in user parameter p
double fxCurve::xp(double p) { return p; }
double fxCurve::yp(double p) {
  if (p < -3.0) {
    return 0.5/(1.0 + exp(-3.0*(p + 6.0)));
  } else {
    return 0.5/(1.0 + exp(3.0*p));
  }
}

// Derivatives w.r.t. the user parameter p
double fxCurve::dxp(double p) { return 1.0; }
double fxCurve::dyp(double p) {
  if (p < -3.0) {
    //return 6.0*exp(-3.0*(p+6))*yp(p)*yp(p);
    return 1.5*exp(3.0*(p+6))/(1.0 + 2.0*exp(3.0*(p + 6.0)) + exp(6.0*(p+6.0)));
  } else {
    //return -6.0*exp(3.0*p)*yp(p)*yp(p);
    return -1.5*exp(3.0*p)/(1.0 + 2.0*exp(3.0*p) + exp(6.0*p));
  }
}

