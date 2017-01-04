// file: matrix.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
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
    /*
  (n == 0)? a = NULL : a = new double [n*n];	// ternary operator
  for (int i = 0; i < n*n; i++){
    a[i] = 0;
  }
     */
  //cout << "matrix n-constructor:" << this;
  //cout << " n = " << n << endl;
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

void Matrix::print()
{
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
      a[i*n+j] = rand()%10;
    }
  }
}
/* not needed?
double Matrix::norm()
{
  double norm = 0, temp_sum;
  for (int i = 0; i < n; i++) {
    temp_sum = 0;
    for (int j = 1; j < n; j++){
      temp_sum += fabs(a[i+j*n]);
    }
    if (temp_sum > norm) {
      norm = temp_sum;
    }
  }
  return norm;
}

*/

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

/* Matrix-Matrix  multiplication operator
 * Usage: M1 *= M2
 */
/* Not needed in this project?
const Matrix &Matrix::operator*=(const Matrix &M)
{
  if (n != M.n) {
    cerr << "Dimensions mismatch, exiting." << endl;
    exit(1);
  }

  double *tmp_a = new double[n*n];
  double tmp_entry;

  //  AB[i,j] = sum_k(A[i,k]*B[k,j])
  
  int i = 0, j = 0;	// row and col
  for (int ij = 0; ij < n*n; ij++) {
    i = ij%n;		// row
    j = ij/n;		// col
    tmp_entry = 0;
    for (int k = 0; k < n; k++) {
      tmp_entry += a[i+k*n] * M.a[k + j*n];
    }
    tmp_a[ij] = tmp_entry;
  }

  for (int i = 0; i < n*n; i++) {
    a[i] = tmp_a[i];
  }
  delete[] tmp_a;

  return *this;
}

 */
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













// matrix.cpp
