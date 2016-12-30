// file: corner.hpp

#ifndef CORNER_HPP
#define CORNER_HPP

#include <memory>
#include "point.hpp"

using namespace std;

class Corner: public Point
{
  private:
    shared_ptr<Point> center;
  public:
    Corner(double dist, double deg, shared_ptr<Point> c);
    ~Corner();
};

#endif 		// CORNER_HPP
