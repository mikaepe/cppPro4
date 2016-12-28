#ifndef XQUAD_HPP
#define XQUAD_HPP


/* xQuad is a derived class of the base class Curvebase. 
 * It is used to represent curves y = c2*x^2+c1*x+c0
 * Constructor: c2, c1, c0 coefficients for quadratic curve, 
 * 	x0,x1 - interval boundaries for x: [x0,x1].
 * Overwrite xp, yp, dxp, dyp.
 */

class xQuad: public Curvebase {
  public:
    xQuad(double cc2, double cc1, double cc0, double x0, double x1);
    ~xQuad();			// Destructor
  
  protected:
    double c2, c1, c0;
    double xp(double p);
    double yp(double p);
    double dxp(double p);
    double dyp(double p); 
};


#endif		// XQUAD_HPP
