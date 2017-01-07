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

    // Overloadings
    Point& operator=(const Point& Q);		// copy-assignment. P = Q;
    const Point operator-() const;		// P = -Q;
    const Point& operator-=(const Point& Q);	// P -= Q;
    const Point operator-(const Point& Q) const;// P-Q;

    // Other member functions
    void zero();
    void print();
    double X() const; // const - obj will not change when called
    double Y() const;
    friend ostream& operator<<(ostream& os, const Point& P);
};


#endif		// POINT_HPP
