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
    double xp(double p) const;
    double yp(double p) const;
    double dxp(double p) const;
    double dyp(double p) const;
};


#endif		// FXCURVE_HPP
