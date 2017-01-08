
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
xLine::~xLine() {}

