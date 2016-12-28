// file: gfctn.hpp

#ifndef GFCTN_HPP
#define GFCTN_HPP

// from slides "Implementation of Grid Functions"

class Gfctn
{
  private:
    Matrix u;
    Domain *grid;

  public:
    Gfctn(Domain *grid_);
    Gfctn(const Gfctn& U);
    Gfctn& operator=(const Gfctn& U);
    Gfctn operator+(const Gfctn& U) const;
    Gfctn operator*(const Gfctn& U) const;

// etc
};

#endif // GFCTN_HPP
