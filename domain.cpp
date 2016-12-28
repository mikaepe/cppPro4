#include <cstdio>	// for writeFile()
#include <iostream>	
#include <cmath>	// for fabs

#include "domain.hpp"
#include "curvebase.hpp"

/*
 * .cpp-file for class domain. See also domain.hpp.
 */


// CONSTRUCTOR --------------------------------------------------------
Domain::Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4) {
  sides[0] = &s1;
  sides[1] = &s2;
  sides[2] = &s3;
  sides[3] = &s4;

  cornersOk = checkCorners();		// Indicator for corners connected
  if (cornersOk == false) {
    sides[0] = sides[1] = sides[2] = sides[3] = NULL;
  }

  m_ = n_ = 0;				// Number of grid points
  x_ = y_ = NULL;			// Arrays for grid coordinates
}

// DESTRUCTOR ---------------------------------------------------------
Domain::~Domain() {		
  if (m_ > 0) {		// Could as well check if n_>0, since both
    delete [] x_;	// need to be positive to generate the grid
    delete [] y_;
  }
}



// MEMBER FUNCTIONS ---------------------------------------------------

// Linear interpolation functions
double Domain::phi1(double t) { 
  return t; 				// phi1(0) = 0, phi1(1) = 1
}
double Domain::phi2(double t) { 
  return 1.0-t; 			// phi2(0) = 1, phi2(1) = 0
}

// Generates the grid and sets it to 
void Domain::grid_generation(int n, int m) {
  if ((n < 1) || (m < 1)) {
    // Need n and m > 0 to generate any grid. Else:
    std::cout << "Warning: Non positive grid size." << std::endl; 
    std::cout << "No grid generated" << std::endl;
    return; 				// No grid is generated
  } else if (cornersOk == false) {
    // Dont generate grid if corners are disconnected
    std::cout << "No grid generated (corner disconnected)" << std::endl;
    return;				// No grid is generated
  }

  if (n != 0) {				// Reset the arrays
    delete[] x_; 
    delete[] y_;
  }

  n_ = n; 
  m_ = m;

  /* The sides' coordinates are computed once only, i.e. there is
   * 4*(n+1)+4*(m+1) calls to x(s) and y(s). If instead, one would
   * call x(s) and y(s) for each of the grid points there would be
   * 16*(n+1)*(m+1) calls. Consider memory if n,m are large.
   */

  double *xLo,*xRi,*xTo,*xLe,*yLo,*yRi,*yTo,*yLe; 

  xLo = new double[n_+1];	// Lower boundary x-coords
  xRi = new double[m_+1];	// Right boundary
  xTo = new double[n_+1];	// Top boundary
  xLe = new double[m_+1];	// Left boundary

  yLo = new double[n_+1];	// same for the y-coords
  yRi = new double[m_+1];
  yTo = new double[n_+1];
  yLe = new double[m_+1];

  double h1= 1.0/n; double h2 = 1.0/m;	// Step sizes

  for (int i=0; i <= n_; i++) {		// Loop the normalized coordinate for x
    xLo[i] = sides[0]->x(i*h1);
    xTo[i] = sides[2]->x(i*h1);
    
    yLo[i] = sides[0]->y(i*h1);
    yTo[i] = sides[2]->y(i*h1);

  }
  for (int j=0; j <= m_; j++) {		// Loop the normalized coordinate for y
    xRi[j] = sides[1]->x(j*h2);
    xLe[j] = sides[3]->x(j*h2);
    
    yRi[j] = sides[1]->y(j*h2);
    yLe[j] = sides[3]->y(j*h2);
  }

  x_ = new double[(n_+1)*(m_+1)];	// x-coordinates for the entire grid
  y_ = new double[(n_+1)*(m_+1)];	// y-coordinates for the same

  for (int i = 0; i <= n_; i++) {
    for (int j = 0; j <= m_; j++) {

      x_[j+i*(m_+1)] = 
	phi2(i*h1)*xLe[j] 		// left side
	+ phi1(i*h1)*xRi[j] 		// right side
	+ phi2(j*h2)*xLo[i] 		// bottom side
	+ phi1(j*h2)*xTo[i] 		// top side
	- phi2(i*h1)*phi2(j*h2)*xLo[0] 	// lower left 
	- phi1(i*h1)*phi2(j*h2)*xLo[n_] // lower right
	- phi2(i*h1)*phi1(j*h2)*xTo[0] 	// top left
	- phi1(i*h1)*phi1(j*h2)*xTo[n_];// top right
	
      y_[j+i*(m_+1)] = 
	phi2(i*h1)*yLe[j] 		// equivalent to x above
	+ phi1(i*h1)*yRi[j]
	+ phi2(j*h2)*yLo[i]
	+ phi1(j*h2)*yTo[i]
	- phi2(i*h1)*phi2(j*h2)*yLo[0]
	- phi1(i*h1)*phi2(j*h2)*yLo[n_]
	- phi2(i*h1)*phi1(j*h2)*yTo[0]
	- phi1(i*h1)*phi1(j*h2)*yTo[n_];
    }
  }	

  delete[] xLo;
  delete[] xRi;
  delete[] xTo;
  delete[] xLe;

  delete[] yLo;
  delete[] yRi;
  delete[] yTo;
  delete[] yLe; 
}


// Function to check if the boundaries are connected (corners)
bool Domain::checkCorners() {
  if (fabs(sides[0]->x(1) - sides[1]->x(0)) > 1e-4 || 
      fabs(sides[0]->y(1) - sides[1]->y(0)) > 1e-4) {
    std::cout << "Low-Right corner disconnected" << std::endl;
    return false;
  } 
  if (fabs(sides[1]->x(1) - sides[2]->x(1)) > 1e-4 || 
      fabs(sides[1]->y(1) - sides[2]->y(1)) > 1e-4) {
    std::cout << "Top-Right corner disconnected" << std::endl;
    return false;
  } 
  if (fabs(sides[2]->x(0) - sides[3]->x(1) > 1e-4) || 
      fabs(sides[2]->y(0) - sides[3]->y(1) > 1e-4)) {
    std::cout << "Top-Left corner disconnected" << std::endl;
    return false;
  } 
  if (fabs(sides[3]->x(0) - sides[0]->x(0)) > 1e-4 || 
      fabs(sides[3]->y(0) - sides[0]->y(0)) > 1e-4) {
    std::cout << "Low-Left corner disconnected" << std::endl;
    return false;
  }
  return true;
}



// Print (for testing) the grid coordinates: Careful if n,m are large.
void Domain::print() {	
  if (n_ < 1 || m_ < 1) {
    std::cout << "No grid to print" << std::endl;
    return;
  }
  for (int i = 0; i < (n_+1)*(m_+1); i++) {
    std::cout << "[" << x_[i] << "," << y_[i] << "]" << std::endl;
  }
}	

// Write the grid to an external file to enable visualization in e.g. matlab.
void Domain::writeFile(){
  if (n_ < 1 || m_ < 1) {
    std::cout << "No grid available for writeFile()" << std::endl;
    return;
  }
  FILE *fp;
  fp =fopen("outfile.bin","wb");
  fwrite(&n_,sizeof(int),1,fp);
  fwrite(&m_,sizeof(int),1,fp);
  fwrite(x_,sizeof(double),(n_+1)*(m_+1),fp);
  fwrite(y_,sizeof(double),(n_+1)*(m_+1),fp);
  fclose(fp);
}

