// file: domain.hpp

#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include <memory>		 	// for shared_ptr (use -std=c++11)
#include "curvebase.hpp"

using namespace std;

class Domain {
  private:
    shared_ptr<Curvebase> sides[4];	// Pointers to curves of the 4 sides
    //Curvebase * sides[4];
    int m_, n_;				// # of grid points in x and y
    double *x_,*y_;			// Arrays for coordinates in grid
    bool cornersOk;			// Corners connected = ok

    inline double phi1(double t) {return t;};		// Linear interpolation functions
    inline double phi2(double t) {return 1.0-t;};

  public:
    // CONSTRUCTOR

    //Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4);
    Domain(shared_ptr<Curvebase> s1, 
	shared_ptr<Curvebase> s2, 
	shared_ptr<Curvebase> s3, 
	shared_ptr<Curvebase> s4);

    // DESTRUCTOR
    ~Domain();

    // FUNCTIONS
    void grid_generation(int n, int m);	// Generates the grid (x_ and y_)
    void print();			// Print points of grid to console
    void writeFile();			// Write points to .bin-file
    bool checkCorners();		// Check if corners are connected

    // new functions for pro4:
    inline int xsize() {return m_;};
    inline int ysize() {return n_;};
    bool gridValid();
    // TODO Point operator()(int i, int j);

};

#endif //DOMAIN_HPP
