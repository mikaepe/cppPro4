// file: point.cpp


/* Source file for class Point. 
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
