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
    double x(double s); 			// Grid coordinate s
    double y(double s); 			// Grid coordinate s
  
  protected:
    double xC;
    double xp(double p);
    double yp(double p);  
    double dxp(double p);
    double dyp(double p); 
    double integrate(double a, double b); 	//Arc length
};


#endif		// YLINE_HPP
