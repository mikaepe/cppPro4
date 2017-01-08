// file: gfctn.cpp

#include <iostream>
#include <cstdlib>	// for exit(1)
#include "gfctn.hpp"

/* Source file for Gfctn class.
 * See gfctn.hpp for declarations.
 * 
 * TODO more comments
 */

// Constructors -------------------------------------------

Gfctn::Gfctn(shared_ptr<Domain> grid_)
  : u(grid_->xsize() + 1, grid_->ysize() + 1), grid(grid_) {}

Gfctn::Gfctn(const Gfctn& U)
  : u(U.u), grid(U.grid) {}

// Destructor ---------------------------------------------

/*
Gfctn::~Gfctn()
{
  // TODO implement destructor
}
*/

// Operator overloadings ---------------------------------
Gfctn& Gfctn::operator=(const Gfctn& U){
    u = U.u;
    grid = U.grid;
    cout << "Copy assignment" << endl;
}

Gfctn& Gfctn::operator=(Gfctn&& U) noexcept {
    u = U.u;
    grid = U.grid;
    U.u = NULL;
    U.grid = nullptr;
    cout << "Move assignment" << endl;
}

Gfctn Gfctn::operator+(const Gfctn& U) const
{
  if (grid == U.grid) { // Defined on same grid?
    Gfctn tmp = Gfctn(grid);
    tmp.u = u + U.u;	// Matrix operator +()
    return tmp;
  } else {
    std::cout << "error: different grids" << std::endl;
    exit(1);
  }
}

Gfctn Gfctn::operator*(const Gfctn& U) const
{
  if (grid == U.grid) {
    Gfctn tmp = Gfctn(grid);
    for (int j = 0; j < grid->ysize(); j++) {
      for (int i = 0; i < grid->xsize(); i++) {
	tmp.u(i,j) = u.get(i,j)*U.u.get(i,j);
      }
    }
    return tmp;
  } else {
    std::cout << "error: different grids (*)" << std::endl;
    exit(1);
  }
}

// Member functions ---------------------------------------

void Gfctn::setFunction(fctnPtr f) // TODO const??
{
  for(int j = 0; j <= grid->ysize(); j++) {
    for(int i = 0; i <= grid->xsize(); i++) {
      u(i,j) = f((*grid)(i,j));
      //cout << (*grid)(i,j) << endl;
    }
  }
}

void Gfctn::print() const 
{
  cout << u << endl;
  // u.print();
}

void Gfctn::writeFile(string fileName) const
{
    u.writeFile(fileName);
}



/* du/dx of grid function u
 * usage: Gfctn DxU = U.D0x();
 * Implementation of derivative from p.13 in slide F_PDEs
 */
Gfctn Gfctn::D0x() const
{
  if (grid->gridValid()) {
    Gfctn tmp(grid);
    double xi, xj, yi, yj, ui, uj;
    double h1 = 1.0 / grid->xsize();
    double h2 = 1.0 / grid->ysize();

    for (int j = 0; j <= grid->ysize(); j++) {
      for (int i = 0; i <= grid->xsize(); i++) { //start at i=1, end at i=n-1
        if (i == 0) {
          xi = ((*grid)(i + 1, j).X() - (*grid)(i, j).X()) / h1;
          yi = ((*grid)(i + 1, j).Y() - (*grid)(i, j).Y()) / h1;
          ui = (u.get(i + 1, j) - u.get(i, j)) / h1;
        } else if (i == grid->xsize()) {
          xi = ((*grid)(i, j).X() - (*grid)(i - 1, j).X()) / h1;
          yi = ((*grid)(i, j).Y() - (*grid)(i - 1, j).Y()) / h1;
          ui = (u.get(i, j) - u.get(i - 1, j)) / h1;
        } else {
          xi = ((*grid)(i + 1, j).X() - (*grid)(i - 1, j).X()) / (2.0 * h1);
          yi = ((*grid)(i + 1, j).Y() - (*grid)(i - 1, j).Y()) / (2.0 * h1);
          ui = (u.get(i + 1, j) - u.get(i - 1, j)) / (2.0 * h1);
        }
        if (j == 0) {
          xj = ((*grid)(i, j + 1).X() - (*grid)(i, j).X()) / h2;
          yj = ((*grid)(i, j + 1).Y() - (*grid)(i, j).Y()) / h2;
          uj = (u.get(i, j + 1) - u.get(i, j)) / h2;
        } else if (j == grid->ysize()) {
          xj = ((*grid)(i, j).X() - (*grid)(i, j - 1).X()) / h2;
          yj = ((*grid)(i, j).Y() - (*grid)(i, j - 1).Y()) / h2;
          uj = (u.get(i, j) - u.get(i, j - 1)) / h2;
        } else {
          xj = ((*grid)(i, j + 1).X() - (*grid)(i, j - 1).X()) / (2.0 * h2);
          yj = ((*grid)(i, j + 1).Y() - (*grid)(i, j - 1).Y()) / (2.0 * h2);
          uj = (u.get(i, j + 1) - u.get(i, j - 1)) / (2.0 * h2);
        }
        tmp.u(i, j) = (ui * yj - uj * yi) / (xi * yj - yi * xj);
      }
    }
    return tmp;
  } else {
      cout << "grid invalid in D0x" << endl;
  }
}


/* du/dy of grid function u
 * Analogous to above
 */
Gfctn Gfctn::D0y() const
{
  if (grid->gridValid()) {
    Gfctn tmp(grid);
    double xi, xj, yi, yj, ui, uj;
    double h1 = 1.0 / grid->xsize();
    double h2 = 1.0 / grid->ysize();

    for (int j = 0; j <= grid->ysize(); j++) {
      for (int i = 0; i <= grid->xsize(); i++) { //start at i=1, end at i=n-1
        if (i == 0) {
          xi = ((*grid)(i + 1, j).X() - (*grid)(i, j).X()) / h1;
          yi = ((*grid)(i + 1, j).Y() - (*grid)(i, j).Y()) / h1;
          ui = (u.get(i + 1, j) - u.get(i, j)) / h1;
        } else if (i == grid->xsize()) {
          xi = ((*grid)(i, j).X() - (*grid)(i - 1, j).X()) / h1;
          yi = ((*grid)(i, j).Y() - (*grid)(i - 1, j).Y()) / h1;
          ui = (u.get(i, j) - u.get(i - 1, j)) / h1;
        } else {
          xi = ((*grid)(i + 1, j).X() - (*grid)(i - 1, j).X()) / (2.0 * h1);
          yi = ((*grid)(i + 1, j).Y() - (*grid)(i - 1, j).Y()) / (2.0 * h1);
          ui = (u.get(i + 1, j) - u.get(i - 1, j)) / (2.0 * h1);
        }
        if (j == 0) {
          xj = ((*grid)(i, j + 1).X() - (*grid)(i, j).X()) / h2;
          yj = ((*grid)(i, j + 1).Y() - (*grid)(i, j).Y()) / h2;
          uj = (u.get(i, j + 1) - u.get(i, j)) / h2;
        } else if (j == grid->ysize()) {
          xj = ((*grid)(i, j).X() - (*grid)(i, j - 1).X()) / h2;
          yj = ((*grid)(i, j).Y() - (*grid)(i, j - 1).Y()) / h2;
          uj = (u.get(i, j) - u.get(i, j - 1)) / h2;
        } else {
          xj = ((*grid)(i, j + 1).X() - (*grid)(i, j - 1).X()) / (2.0 * h2);
          yj = ((*grid)(i, j + 1).Y() - (*grid)(i, j - 1).Y()) / (2.0 * h2);
          uj = (u.get(i, j + 1) - u.get(i, j - 1)) / (2.0 * h2);
        }
        tmp.u(i, j) = (- ui * xj + uj * xi) / (xi * yj - yi * xj);
      }
    }
    return tmp;
  } else {
    cout << "grid invalid in D0y" << endl;
  }
}


/*
Gfctn Gfctn::DD0x() const
{
  Gfctn tmp(grid);
  double h;
  if (grid->gridValid()) {
    // This implementation actually assumes constant grid size (constant h)
    for (int j = 0; j <= grid->ysize(); j++) {
      for (int i = 1; i < grid->xsize(); i++) {
	h = 0.5*((*grid)(i+1,j).X()-(*grid)(i-1,j).X());
	tmp.u(i,j) = (u.get(i-1,j) - 2*u.get(i,j) + u.get(i+1,j))/(h*h);
      }
    }
  } else {
    cout << "grid invalid in DD0x" << endl;
  }
  return tmp;
}
*/


/* Second derivative of u w.r.t. x.
 * Implementation from p.13-14 slide F_PDEs
 */
Gfctn Gfctn::DD0x2() const
{
  Gfctn tmp(grid);
  tmp = D0x();
  tmp = tmp.D0x();
    /*
  double xp2,xp1,x,xm1,xm2;	// x_{i+2,j},x_{i+1,j},...etc
  if (grid->gridValid()) {
    for (int j = 0; j <= grid->ysize(); j++) {
      for (int i = 2; i <= grid->xsize()-2; i++) {
	xp2 = (*grid)(i+2,j).X();
	xp1 = (*grid)(i+1,j).X();
	x = (*grid)(i,j).X();
	xm1 = (*grid)(i-1,j).X();
	xm2 = (*grid)(i-2,j).X();

	tmp.u(i,j) = (1.0/(xp1-xm1))*(
	    (u.get(i+2,j)-u.get(i,j))/(xp2 - x) - 
	    (u.get(i,j) - u.get(i-2,j))/(x-xm2));
      }
    }
  } else {
    cout << "grid invalid in DD0x" << endl;
  }*/
  return tmp;
}


/* Second derivative of u w.r.t. y.
 */
Gfctn Gfctn::DD0y2() const
{
  Gfctn tmp(grid);
  double yp2,yp1,y,ym1,ym2;	// y_{i,j+2},y_{i,j+1},...etc
  if (grid->gridValid()) {
    for (int i = 0; i <= grid->xsize(); i++) {
      for (int j = 2; j <= grid->ysize()-2; j++) {
	yp2 = (*grid)(i,j+2).Y();
	yp1 = (*grid)(i,j+1).Y();
	y = (*grid)(i,j).Y();
	ym1 = (*grid)(i,j-1).Y();
	ym2 = (*grid)(i,j-2).Y();

	tmp.u(i,j) = (1.0/(yp1-ym1))*(
	    (u.get(i,j+2)-u.get(i,j))/(yp2 - y) - 
	    (u.get(i,j) - u.get(i,j-2))/(y-ym2));
      }
    }
  } else {
    cout << "grid invalid in DD0x" << endl;
  }
  return tmp;
}


/* Laplacian of grid function
 */
Gfctn Gfctn::laplace() const
{
  Gfctn laplace = D0x().D0x() + D0y().D0y();
  return laplace;
}













// file: gfctn.cpp
