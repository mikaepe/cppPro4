// file: curvebase.hpp

#ifndef CURVEBASE_HPP
#define CURVEBASE_HPP

#include <cmath>
#include <iostream>


class Curvebase {
private:
  double newtonsolve(double p0, double s) const;

  double i2Simpson(double a, double b) const;

  double iSimpson(double a, double b) const;

  double dL(double t) const;      // integrand for arc length


protected:
  double a;
  double b;
  double length;

  // Pure virtual, ("= 0"), derived classes must implement:
  virtual double xp(double p) const = 0;  //parametrized by user
  virtual double yp(double p) const = 0;  //parametrized by user
  virtual double dxp(double p) const = 0;  //dx(p)/dp for arc length
  virtual double dyp(double p) const = 0;  //dy(p)/dp for arc length

  double integrate(double a, double b) const;  // TODO private?

public:
  Curvebase();      //default constructor
  virtual double x(double s) const;  //parametrized by normalized arc length
  virtual double y(double s) const;  //parametrized by normalized arc length

  // TODO from slides 6 F_Inheritance.pdf page 30:
  // the destructor of abstract base class should always be virtual
  // virtual ~Curvebase();

};

#endif		// CURVEBASE_HPP
