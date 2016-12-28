#ifndef FXCURVE_HPP
#define FXCURVE_HPP

/* fxCurve: Derived class from base class Curvebase.
 * Constructor: interval length in x: [x0,x1].
 */

class fxCurve: public Curvebase{
  public: 
    fxCurve(double xx0, double xx1);	// Constructor
    ~fxCurve();				// Destructor

  protected:
    double xp(double p);
    double yp(double p);
    double dxp(double p);
    double dyp(double p);
};


#endif		// FXCURVE_HPP
