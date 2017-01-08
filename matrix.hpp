// file: matrix.hpp

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix
{
  private:
    int m, n;	// matrix dim.
    double *a;	// matrix elements

  public:
    // Constructors and destructors
    Matrix(int n_ = 0, int m_ = 0);
    Matrix(const Matrix &M);
    ~Matrix();

    // Functions
    void fillMatrix(double b[]);
    void identity();
    void print() const;
    inline int rowSizeMatrix() const {return n;}
    inline int colSizeMatrix() const {return m;}
    void randomize();
    void writeFile(std::string fileName) const;
    inline double get(int i, int j) const {
      return a[i*m+j];			// get element from matrix
    }

    // Operator overloadings
    Matrix &operator=(const Matrix &M);
    Matrix &operator=(Matrix &&M) noexcept;
    const Matrix &operator*=(const double d);
    const Matrix &operator+=(const Matrix &M);
    const Matrix operator+(const Matrix& M) const;
    double& operator()(int i, int j) const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
};

#endif // MATRIX_HPP
