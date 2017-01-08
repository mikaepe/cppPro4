// file: corner.cpp

#include <cmath>
#include <iostream>
#include "corner.hpp"

using namespace std;

// Constructor
Corner::Corner(double dist, double deg, shared_ptr<Point> c)
{
  center = c;
  x = dist*cos(deg) + c->X();
  y = dist*sin(deg) + c->Y();
  cout << "Corner constructor: " << this << endl;
}

// Destructor
Corner::~Corner()
{
  cout << "Corner  destructor: " << this << endl;
}


