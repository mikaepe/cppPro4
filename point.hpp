// file: point.hpp

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;


class Point 
{
  private:
    double x;
    double y;

  public:

    // Constructors and destructor
    Point(double xx = 0.0, double yy = 0.0);	// constructor
    Point(const Point& Q);			// copy constructor
    ~Point();					// destructor
    
    // Member functions
    double X() const { return x; } 
    double Y() const { return y; }
    friend ostream& operator<<(ostream& os, const Point& P);
};


#endif		// POINT_HPP
