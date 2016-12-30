// file: gfctn.hpp

#ifndef GFCTN_HPP
#define GFCTN_HPP

#include <memory>	// for shared_ptr (use -std=c++11)

// from slides "Implementation of Grid Functions"

class Gfctn
{
  private:
    Matrix u;
    shared_ptr<Domain> grid;

  public:
    Gfctn(shared_ptr<Domain> grid_);
    Gfctn(const Gfctn& U);
    Gfctn& operator=(const Gfctn& U);
    Gfctn operator+(const Gfctn& U) const;
    Gfctn operator*(const Gfctn& U) const;

// etc
};

#endif // GFCTN_HPP
