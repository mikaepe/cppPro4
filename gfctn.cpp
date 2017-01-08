// file: gfctn.cpp

#include <iostream>
#include "gfctn.hpp"

/* Source file for Gfctn class.
 * See gfctn.hpp for declarations.
 * 
 * TODO more comments
 */

// Constructors -------------------------------------------

Gfctn::Gfctn(shared_ptr<Domain> grid_)
  : u(grid_->xsize() + 1, grid_->ysize() + 1), grid(grid_) {}

Gfctn::Gfctn(const Gfctn &U)
  : u(U.u), grid(U.grid) {}

// Destructor ---------------------------------------------

/*
Gfctn::~Gfctn()
{
  // TODO implement destructor
}
*/

// Operator overloadings ---------------------------------

// Copy assignment
Gfctn &Gfctn::operator=(const Gfctn &U) {
  u = U.u;
  grid = U.grid;
  return *this;
}

// Move assignment
Gfctn &Gfctn::operator=(Gfctn &&U) noexcept {
  u = U.u;
  grid = U.grid;
  U.u = Matrix();
  U.grid = nullptr;
  return *this;
}

Gfctn Gfctn::operator+(const Gfctn &U) const {
  if (grid == U.grid) { // Defined on same grid?
    Gfctn tmp = Gfctn(grid);
    tmp.u = u + U.u;  // Matrix operator +()
    return tmp;
  } else {
    std::cout << "error: different grids" << std::endl;
    exit(1);
  }
}

Gfctn Gfctn::operator*(const Gfctn &U) const {
  if (grid == U.grid) {
    Gfctn tmp = Gfctn(grid);
    for (int j = 0; j < grid->ysize(); j++) {
      for (int i = 0; i < grid->xsize(); i++) {
        tmp.u(i, j) = u.get(i, j) * U.u.get(i, j);
      }
    }
    return tmp;
  } else {
    std::cout << "error: different grids (*)" << std::endl;
    exit(1);
  }
}

// Member functions ---------------------------------------

/* setFunction
 * Computes the value of the function f in all grid points and puts in the matrix u
 *
 */
void Gfctn::setFunction(const fctnPtr f)
{
  for (int j = 0; j <= grid->ysize(); j++) {
    for (int i = 0; i <= grid->xsize(); i++) {
      u(i, j) = f((*grid)(i, j));
      //cout << (*grid)(i,j) << endl;
    }
  }
}



/* du/dx of grid function u
 * usage: Gfctn DxU = U.D0x();
 * Implementation of derivative from p.13 in slide F_PDEs
 */
Gfctn Gfctn::D0x() const {
  Gfctn tmp(grid);
  if (grid->gridValid()) {
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
  } else {
    cout << "grid invalid in D0x" << endl;

  }
  return tmp;
}


/* du/dy of grid function u
 * Analogous to above
 */
Gfctn Gfctn::D0y() const {
  Gfctn tmp(grid);
  if (grid->gridValid()) {
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
        tmp.u(i, j) = (-ui * xj + uj * xi) / (xi * yj - yi * xj);
      }
    }
  } else {
    cout << "grid invalid in D0y" << endl;
  }
  return tmp;
}

/* Laplacian of grid function
 */
Gfctn Gfctn::laplace() const {
  Gfctn laplace = D0x().D0x() + D0y().D0y();
  return laplace;
}



// file: gfctn.cpp
