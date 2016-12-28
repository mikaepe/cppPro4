
#include <cmath>
#include <iostream>
#include "curvebase.hpp"


Curvebase::Curvebase() {}; // Default constructor


/* Integrate , i2Simpson, iSimpson all taken
 * directly from project 1.
 */
inline double Curvebase::i2Simpson(double a, double b) {
  return iSimpson(a,0.5*(a+b)) + iSimpson(0.5*(a+b),b);
}

inline double Curvebase::iSimpson(double a, double b) {
  return ((b-a)/6.0)*(dL(a)+4.0*dL(0.5*(a+b)) + dL(b));
}

inline double Curvebase::dL(double p) {
  return sqrt(dxp(p)*dxp(p) + dyp(p)*dyp(p));
}

double Curvebase::integrate(double a, double b){

  double tolI = 1e-8;
  double I = 0, I1, I2, errest;
  int node = 1;

  while (true) {
    I1 = iSimpson(a,b);
    I2 = i2Simpson(a,b); 
    errest = std::abs(I1-I2);
    if (errest < 15*tolI) { //if leaf
      I += I2;
      while (node % 2 != 0) { // while uneven node

	if (node == 1) { 
	  return I; // return if we are back at root again
	}

	node = 0.5*node;	
	a = 2*a-b;
	tolI *= 2;
      }
      // First even node: go one node up - go to right child
      b = 2*b-a;
      node = node+1;
      a = 0.5*(a+b);
    } else { //if not a leaf: go to left child
      node *= 2;
      b = 0.5*(a+b);
      tolI *= 0.5;
    }
  }
  return I;
}


/* Newton solver for equation f(p) = l(p) - s*l(b)
 * input: p0 is initial guess for Newtons method.
 */
double Curvebase::newtonsolve(double p0, double s) {

  int iter = 0, maxiter = 150;
  double tolN = 1e-6;
  double err = 1.0;	
  double p1,p;
  p = p0;
  while (err > tolN && iter < maxiter) {

    p1 = p - (integrate(a,p)-s*length)/dL(p);	// Newtons method
    err = fabs(p1 - p);				// Check error
    p = p1; iter++;				// Update
  }

  if (iter == maxiter) {			// maxiter reached
    std::cout << "No convergence in Newton solver" << std::endl;
  }

  return p;
}


// Curve parametrized by grid coordinate
double Curvebase::x(double s){
  double p, p0;
  p0 = a + s*length;				// Initial guess for Newtons meth.
  p = newtonsolve(p0,s);
  return xp(p);
}

// Curve parametrized by grid coordinate
double Curvebase::y(double s){
  double p, p0;
  p0 = a + s*length;				// Initial guess for Newtons meth.
  p = newtonsolve(p0,s);
  return yp(p);
}

