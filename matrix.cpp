// file: matrix.cpp

#include <iostream>
#include <iomanip>	// for setprecision in operator<<
#include <cstdlib>	// for exit()
#include <ctime>	// for rand() and srand()
#include <cmath>
#include "matrix.hpp"

/* Source file for Matrix class.
 * See matrix.hpp for declarations
 * This class implements matrix using C-style array
 * a[i+j*n] is the element on row i, col j i.e. A[i,j].
 */

using namespace std;

// Constructors	-------------------------------------------

Matrix::Matrix(int n_, int m_): m(m_), n(n_), a(nullptr)
{
  if (m*n > 0) {
    a = new double[m*n];
    fill(a,a+m*n,0.0);
  }
}

Matrix::Matrix(const Matrix &M)
{
  n = M.n;
  m = M.m;
  a = new double [m*n];
  for (int i = 0; i < n*m;  i++) {
    a[i] = M.a[i];
  }
  //cout << "matrix copy-constructor:" << this << endl;
}

// Destructor	-------------------------------------------

Matrix::~Matrix()
{
  delete[] a;
}

// Member functions	-----------------------------------

void Matrix::fillMatrix(double b[])
{
  for (int i = 0; i < m*n; i++) {
    a[i] = b[i];
  }
}

void Matrix::identity() 
{
  if (n!=m) {
    cout << "A non-square matrix can not be the identity matrix" << endl;
    return;
  }
  for (int i = 0; i < n*n; i++) {
    (i%n == i/n)? a[i] = 1: a[i] = 0;
  }
}

void Matrix::print() const
{
  cout << endl;
  if (n == 0 || m == 0) {
    cout << "[]" << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[j + i*m] << " ";
    }
    cout << endl;
  }
}

int Matrix::rowSizeMatrix()
{
  return n;
}

int Matrix::colSizeMatrix()
{
  return m;
}

void Matrix::randomize()
{
  if (n == 0 || m == 0) {
      cout << "empty matrix, no randomizing done" << endl;
      return;
  }
  //srand(time(0)); gives the same random number every time
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { // TODO make single loop
      a[i*m+j] = rand()%10;
    }
  }
}



// Operator overloadings	---------------------------

/* Equality operator
 * Usage: M1 = M2; where M1 and M2 are Matrix-obj.
 */
Matrix &Matrix::operator=(const Matrix &M)
{
  if (this == &M) {
    return *this;
  }
  if (n == M.n && m == M.m) {
    for (int i = 0; i < n*m; i++) {
      a[i] = M.a[i];
    }
  } else {
    if (a) {	// if initialized, delete a
      delete a;
    }
    n = M.n;
    m = M.m;
    a = new double[n*m];
    for (int i = 0; i < n*m; i++) {
      a[i] = M.a[i];
    }
  }
  return *this;
}

/* Matrix-scalar multiplication operator
 * Usage: M *= d; where M is Matrix-obj and d is double
 */
const Matrix &Matrix::operator*=(const double d)
{
  for (int i = 0; i < n*m; i++) {
    a[i] *= d;
  }
  return *this;
}

/* Matrix addition operator
 * Usage: M1 += M2
 */
const Matrix &Matrix::operator+=(const Matrix &M)
{
  if(n != M.n || m != M.m) {
    cerr << "Dimensions mismatch in sum. Exiting." << endl;
    exit(1);
  }
  for (int i = 0; i < n*m; i++) {
    a[i] += M.a[i];
  }

  return *this;
}

/* Matrix addition operator
 * Usage: A = B+C;
 */
const Matrix Matrix:: operator+(const Matrix &M) const
{
  if (n != M.n || m != M.m) {
    cerr << "Dimensions mismatch in sum. Exiting" << endl;
    exit(1);
  }
  Matrix A(n,m);
  for (int i = 0; i < n*m; i++) {
    A.a[i] = a[i]+M.a[i];
  }
  return A;
}



/* Matrix element access operator
 * Usage: e = M(i,j)
 */
double& Matrix:: operator()(int i, int j) const
{
  if (i < 0 || i >= n || j < 0 || j >= m) {
    cerr << "Bad index in matrix" << endl;
    exit(1);
  }
  return a[j+i*m];
}

/* Stream insertion operator
 * Usage: cout << M << endl;
 */
ostream& operator<<(ostream& os, const Matrix& M)
{
  int n = M.n;
  int m = M.m;
  os << endl;
  os << fixed << setprecision(4);
  if (n <= 0 || m <= 0) {
    os << "[]" << endl;
    return os;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (M.a[j + i*m] >= 0) {
	os << " ";
      }
      os << M.a[j + i*m] << "  ";
    }
    os << endl;
  }
  return os;
}


// matrix.cpp
