// file: gfctn.hpp

#ifndef GFCTN_HPP
#define GFCTN_HPP

#include <memory>	// for shared_ptr (use -std=c++11)
#include "matrix.hpp"
#include "domain.hpp"

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
    Gfctn& operator=(const Gfctn& U);	// TODO implementerad? Behövs inte?
    Gfctn& operator=(Gfctn&& U) noexcept;
    Gfctn operator+(const Gfctn& U) const;
    Gfctn operator*(const Gfctn& U) const;

    // MEMBER FUNCTIONS
    void setFunction(fctnPtr f);	// set grid function values
    void print() const;			// print grid values
    void writeFile(std::string fileName) const; //write to binary file
    Gfctn D0x() const;			// du/dx
    Gfctn D0y() const;			// du/dy
    //Gfctn DD0x() const;			// d2u/dx2
    Gfctn DD0x2() const;		// d2u/dx2
    Gfctn DD0y2() const;		// d2u/dy2
    Gfctn laplace() const;		// d2u/dx2 + d2u/dy2


// etc
};

#endif // GFCTN_HPP
