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

Gfctn::~Gfctn()
{
  // TODO implement destructor
}

// Operator overloadings ---------------------------------	

Gfctn Gfctn::operator+(const Gfctn& U) const
{
  if (grid == U.grid) { // Defined on same grid?
    tmp = new Gfctn(grid);
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
    tmp = new Gfctn(grid);
    for (int j = 0; j < grid.ysize(); j++) {
      for (int i = 0; i < grid.xsize(); i++) {
	tmp.u(i,j) = u(i,j)*U.u(i,j);
      }
    }
    return tmp;
  } else {
    std::cout << "error: different grids (*)" << std::endl;
    exit(1);
  }
}
