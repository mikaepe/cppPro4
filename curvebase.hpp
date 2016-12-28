#ifndef CURVEBASE_HPP
#define CURVEBASE_HPP

#include <cmath>
#include <iostream>



class Curvebase {
  
  protected:
    double a;
    double b;
    double length;

    
    virtual double xp(double p) = 0;	//parametrized by user
    virtual double yp(double p) = 0;	//parametrized by user
    virtual double dxp(double p) = 0;	//dx(p)/dp for arc length
    virtual double dyp(double p) = 0;	//dy(p)/dp for arc length
    
    double integrate(double a, double b);
    double newtonsolve(double p0, double s);

    double i2Simpson(double a, double b);
    double iSimpson(double a, double b); 
    double dL(double t);			// integrand for arc length
  
  public:
    Curvebase(); 			//default constructor
    virtual double x(double s); 	//parametrized by normalized arc length
    virtual double y(double s); 	//parametrized by normalized arc length

};

#endif		// CURVEBASE_HPP
