// file: xline.hpp

#ifndef XLINE_HPP
#define XLINE_HPP


/* xLine: curves for lines with constant y.
 * Derived class from base class Curvebase.
 * Constructor: y0 constant y, 
 * 	x0, x1 interval in x: [x0, x1].
 * Overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s).
 */

#include "curvebase.hpp"

class xLine: public Curvebase{
  public:
    xLine(double x0, double x1, double y0)	// Constructor
    {
      a = x0;
      b = x1;
      yConst = y0;
      length = x1 - x0;
    }
    ~xLine() {}					// Destructor

    // Overwrite x(s) and y(s) in normalized coordinates
    double x(double s) const { return a+s*length; }
    double y(double s) const { return yConst; }
  
  protected:
    double yConst;

    // user parametrizations 
    double xp(double p) const { return p; }
    double yp(double p) const { return yConst; }
    double dxp(double p) const { return 1.0; }
    double dyp(double p) const { return 0.0; }

    // Arc length
    double integrate(double a, double b) const { return b-a; }
};

#endif		// XLINE_HPP
