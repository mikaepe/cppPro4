#ifndef XLINE_HPP
#define XLINE_HPP


/* xLine: curves for lines with constant y.
 * Derived class from base class Curvebase.
 * Constructor: y0 constant y, 
 * 	x0, x1 interval in x: [x0, x1].
 * Overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s).
 */

class xLine: public Curvebase{
  public:
    xLine(double x0, double x1, double y0);	// Constructor
    ~xLine();					// Destructor
    double x(double s) const; 			// Grid coordinate s
    double y(double s) const; 			// Grid coordinate s
  
  protected:
    double yConst;
    double xp(double p) const;
    double yp(double p) const;
    double dxp(double p) const;
    double dyp(double p) const;
    double integrate(double a, double b) const; 	// Arc length
};


#endif		// XLINE_HPP
