// file: point.cpp

#include <iostream>
#include "point.hpp"

using namespace std;

// Constructor
Point::Point() 
{
  cout << "Point  def.constr: " << this << endl;
};

Point::Point(double xx = 0, double yy = 0): x(xx), y(yy) 
{
  cout << "Point constructor: " << this << endl;
}

// Destructor
Point::~Point()
{
  cout << "Point  destructor: " << this << endl;
}

double Point::X() const
{
  return x;
}

double Point::Y() const
{
  return y;
}

void Point::zero()
{
  x = y = 0;
}

void Point::print()
{
  std::cout << "[" << x << "," << y << "]" << std::endl;
}

