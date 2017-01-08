
#include "curvebase.hpp"
#include "xquad.hpp"

// Constructor
xQuad::xQuad(double cc2, double cc1, double cc0, double x0, double x1) {
  c2 = cc2;
  c1 = cc1;
  c0 = cc0;
  a = x0;
  b = x1;
  length = integrate(a,b);
}

// Destructor
xQuad::~xQuad() {}

// Curve parametrized by user parameter
double xQuad::xp(double p) const { return p;}
double xQuad::yp(double p) const { return c2*p*p+c1*p + c0; }

// Derivatives w.r.t. the user parameter
double xQuad::dxp(double p) const { return 1; }
double xQuad::dyp(double p) const { return 2*c2*p + c1;}

