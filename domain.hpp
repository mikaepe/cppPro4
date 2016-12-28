#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include "curvebase.hpp"

class Domain {
  private:
    Curvebase * sides[4];		// Pointers to curves of the 4 sides
    int m_, n_;				// # of grid points in x and y
    double *x_,*y_;			// Arrays for coordinates in grid
    bool cornersOk;

    double phi1(double t);		// Linear interpolation functions
    double phi2(double t);		

  public:
    // CONSTRUCTOR
    Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4);

    // DESTRUCTOR
    ~Domain();

    // FUNCTIONS
    void grid_generation(int n, int m);	// Generates the grid (x_ and y_)
    void print();			// Print points of grid to console
    void writeFile();			// Write points to .bin-file (use matlab to view)
    bool checkCorners();		// Check if corners are connected
};

#endif //DOMAIN_HPP
