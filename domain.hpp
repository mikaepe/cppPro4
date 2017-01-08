// file: domain.hpp

#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include <memory>		 	// for shared_ptr (use -std=c++11)
#include "curvebase.hpp"
#include "point.hpp"

using namespace std;

class Domain {
  private:
    shared_ptr<Curvebase> sides[4];	// Pointers to curves of the 4 sides
    int n_, m_;				// # of grid points in x and y
    double *x_,*y_;			// Arrays for coordinates in grid
    bool cornersOk;			// Corners connected = ok

    inline double phi1(double t) const {return t;};		// Linear interpolation functions
    inline double phi2(double t) const {return 1.0-t;};

  public:
    // CONSTRUCTOR

    Domain(shared_ptr<Curvebase> s1,	
	shared_ptr<Curvebase> s2, 
	shared_ptr<Curvebase> s3, 
	shared_ptr<Curvebase> s4);

    // DESTRUCTOR
    ~Domain();

    
    Point operator()(int i, int j) const;	// Coordinates at i,j

    // FUNCTIONS
    void grid_generation(int n, int m);	// Generates the grid (x_ and y_)
    void print() const;			// Print points of grid to console
    void writeFile(std::string fileName) const;			// Write points to .bin-file
    bool checkCorners() const;		// Check if corners are connected

    // new functions for pro4:
    inline int xsize() const {return n_;};
    inline int ysize() const {return m_;};
    bool gridValid() const;

};

#endif //DOMAIN_HPP
