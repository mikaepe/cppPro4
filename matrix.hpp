// file: matrix.hpp

#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix
{
  private:
    int n;	// matrix dim.
    double *a;	// matrix elements

  public:
    // Constructors and destructors
    Matrix(int nn = 0);
    Matrix(const Matrix &M);
    ~Matrix();

    // Functions
    void fillMatrix(double b[]);
    void identity();
    void print();
    int  sizeMatrix();
    void randomize();
    double norm();

    // Operator overloadings
    Matrix &operator=(const Matrix &M);
    const Matrix &operator*=(const double d);
    const Matrix &operator*=(const Matrix &M);
    const Matrix &operator+=(const Matrix &M);
};

#endif // MATRIX_HPP
