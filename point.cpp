// file: point.cpp


/* Source file for class Point. 
 * Constructor, copy constructor, destructor.
 * Copy assignment overloading, overloadings of operators
 * for P = -Q; P -= Q; P = Q1-Q2;
 * Member access functions for cartesian coordinates.
 * Function to set point to origin.
 * Friend overloading for output stream.
 *
 * See also point.hpp for declarations
 */

#include "point.hpp"

using namespace std;


// CONSTRUCTORS AND DESTRUCTORS 	---	---	---	---


// constructor using initializer list
Point::Point(double xx, double yy) : 
  x(xx), 
  y(yy) 
{}

// Copy constructor
Point::Point(const Point& Q) :
  x(Q.x), y(Q.y) 
{}

// destructor
Point::~Point()
{}


// OPERATOR OVERLOADINGS	---	---	---	---	---

/*
// copy-assignment
Point& Point:: operator=(const Point& Q)
{
  if (this != &Q) {
    x = Q.x;
    y = Q.y;
  }
  return *this;	// dereferencing
}

// negative operator i.e. P = -Q;
const Point Point:: operator-() const
{
  return Point(-x,-y);
}

// "reduce by" operator i.e. P -= Q;
const Point& Point:: operator-=(const Point& Q)
{
  x -= Q.x;
  y -= Q.y;
  return *this;
}

// minus operator i.e. P-Q
const Point Point:: operator-(const Point& Q) const
{
  return Point(x-Q.x,y-Q.y);
}

// MISC. MEMBER FUNCTIONS	---	---	---	---	---

// set x = y = 0, i.e. point at origin.
void Point::zero()
{
  x = y = 0.0;
}

// standard member function print()
void Point::print()
{
  cout << "[" << x << "," << y << "]" << endl;
}
*/

// member access function for x
double Point::X() const
{
  return x;
}

// member access function for y
double Point::Y() const
{
  return y;
}


//	---	---	---	---	---	---

// output operator for ostream
ostream& operator<<(ostream& os, const Point& P)
{
  os << "[" << P.x << "," << P.y << "]"; //friend function
  return os;
}
