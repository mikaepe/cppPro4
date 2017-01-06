// file: matrix.hpp

#ifndef MATRIX_HPP
#define MATRIX_HPP

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
    int rowSizeMatrix();
    int colSizeMatrix();
    void randomize();
    inline double get(int i, int j) const {
      return a[i*m+j];			// get element from matrix
    }

    // Operator overloadings
    Matrix &operator=(const Matrix &M);
    const Matrix &operator*=(const double d);
    const Matrix &operator+=(const Matrix &M);
    const Matrix operator+(const Matrix& M) const;
    double& operator()(int i, int j) const;
};

#endif // MATRIX_HPP
