// file: gfctn.hpp

#ifndef GFCTN_HPP
#define GFCTN_HPP

#include <memory>	// for shared_ptr (use -std=c++11)
#include "matrix.hpp"
#include "domain.hpp"
#include "point.hpp"

// from slides "Implementation of Grid Functions"

typedef double (*fctnPtr)(Point);

class Gfctn
{
  private:
    Matrix u;
    shared_ptr<Domain> grid;

  public:
    // CONSTRUCTORS
    Gfctn(shared_ptr<Domain> grid_);
    Gfctn(const Gfctn& U);

    // OPERATORS
    Gfctn& operator=(const Gfctn& U);
    Gfctn operator+(const Gfctn& U) const;
    Gfctn operator*(const Gfctn& U) const;

    // MEMBER FUNCTIONS
    void setFunction(fctnPtr f);
    void print() const;


// etc
};

#endif // GFCTN_HPP
