#ifndef YLINE_HPP
#define YLINE_HPP


/* yLine: curves for lines with constant x.
 * Derived class from base class Curvebase.
 * Constructor: x0 is constant x,
 * 	y0, y1 interval in y: [y0,y1].
 * Overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 */

class yLine: public Curvebase{
  public:
    yLine(double y0, double y1, double x0);	// Constructor
    ~yLine();					// Destructor
    double x(double s) const; 			// Grid coordinate s
    double y(double s) const; 			// Grid coordinate s
  
  protected:
    double xC;
    double xp(double p) const;
    double yp(double p) const;
    double dxp(double p) const;
    double dyp(double p) const;
    double integrate(double a, double b) const; 	//Arc length
};


#endif		// YLINE_HPP
