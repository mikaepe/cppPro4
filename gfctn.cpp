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



/* du/dx of grid function u
 * usage: Gfctn DxU = U.D0x();
 * Implementation of derivative from p.13 in slide F_PDEs
 */
Gfctn Gfctn::D0x() const
{
  Gfctn tmp(grid);
  double xminus, xplus;
  if (grid->gridValid()) {
    for (int j = 0; j <= grid->ysize(); j++) {
      for (int i = 1; i < grid->xsize(); i++) { //start at i=1, end at i=n-1
	xminus = (*grid)(i-1,j).X();
	xplus = (*grid)(i+1,j).X();
	tmp.u(i,j) = (u.get(i-1,j)-u.get(i+1,j))/(xplus-xminus);
      }
    }
  } else {
    cout << "grid invalid in D0x" << endl;
  }
  return tmp;
}


/* du/dy of grid function u
 * Analogous to above
 */
Gfctn Gfctn::D0y() const
{
  Gfctn tmp(grid);
  double yminus, yplus;
  if (grid->gridValid()) {
    for (int i = 0; i <= grid->xsize(); i++) {
      for (int j = 1; j < grid->ysize(); j++) { //start at j=1, end at j=m-1
	yminus = (*grid)(i,j-1).Y();
	yplus = (*grid)(i,j+1).Y();
	tmp.u(i,j) = (u.get(i,j-1)-u.get(i,j+1))/(yplus-yminus);
      }
    }
  } else {
    cout << "grid invalid in D0x" << endl;
  }
  return tmp;
}

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


















// file: gfctn.cpp
