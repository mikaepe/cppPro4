#ifndef YLINE_HPP
#define YLINE_HPP


/* yLine: curves for lines with constant x.
 * Derived class from base class Curvebase.
 * Constructor: x0 is constant x,
 * 	y0, y1 interval in y: [y0,y1].
 * Overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 */

#include "curvebase.hpp"

class yLine: public Curvebase{
  public:
    yLine(double y0, double y1, double x0)	// Constructor
    {
      a = y0;
      b = y1;
      xC = x0;
      length = y1 - y0;
    }
    ~yLine() {}					// Destructor

    // Overwrite x(s) and y(s) in normalized coordinates
    double x(double s) const { return xC; } 
    double y(double s) const { return a+s*length; }
  
  protected:
    double xC;

    // user parametrizations
    double xp(double p) const { return xC; }
    double yp(double p) const { return p; }
    double dxp(double p) const { return 0.0; }
    double dyp(double p) const { return 1.0; }

    // Arc length
    double integrate(double a, double b) const { return b-a; }
};


#endif		// YLINE_HPP
