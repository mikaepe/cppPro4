// file: point.hpp

#ifndef POINT_HPP
#define POINT_HPP

/* 
 * Basic class for points in 2-space
 */

class Point
{
  protected:
    double x,y;

  public:
    Point();
    Point(double xx, double yy);
    ~Point();

    double X() const;
    double Y() const;
    void print();
    void zero();
    
};

#endif	// POINT_HPP
