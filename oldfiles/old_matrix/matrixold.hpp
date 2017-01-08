// Matrix class (Hanna Hultin, Mikael Persson)

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include<cmath>

/* Matrix class
 * M = Matrix(5) gives 5x5-matrix of zeros.
 *
 */

class Matrix 
{
  private:
    int m;
    double **a;
  
  public:
    
    // CONSTRUCTORS	:::	:::	:::	:::	:::
    
    Matrix() {};            	// Default constr.

    // Initializes a square matrix of zeros
    Matrix(int mm) : m(mm) {
      a = new double *[m];
      for (int i = 0; i < m; i++) {
	a[i] = new double[m];
	for (int j = 0; j < m; j++) {
	  a[i][j] = 0;		// 0's in all elements
	}
      }
    }

    /* Copy constructor, usage:
     * M2 = M, where M is Matrix object
     */
    Matrix(const Matrix &M) {
      m = M.m;			// size of square matrix	
      a = new double *[m];	// constructs a using values from M
      for (int i = 0; i < m; i++) {
	a[i] = new double[m];
	for (int j = 0; j < m; j++) {
	  a[i][j] = M.a[i][j];	// each element from M
	}
      }
    }

    // Destructor
    ~Matrix() {
      for (int i = 0; i < m; i++) {
	delete[] a[i];
      }
      delete[] a;
      a = NULL;
    }


    // OPERATOR OVERLOADINGS	:::	:::	:::	:::

    /* Equality operator:
     * Equates Matrix to M (other Matrix object)
     */
    Matrix &operator=(const Matrix &M) {
      if (this == &M) {
	return *this;
      }
      if (m == M.m) { // if same dimension, just change the elements
	for (int i = 0; i < m; i++) {
	  for (int j = 0; j < m; j++) {
	    a[i][j] = M.a[i][j];
	  }
	}
      } else {
	if (!a) { // if a initialized, delete a
	  for (int i = 0; i < m; i++) {
	    delete[] a[i];
	  }
	  delete[] a;
	}
	m = M.m;
	a = new double *[m];
	for (int i = 0; i < m; i++) {
	  a[i] = new double[m];
	  for (int j = 0; j < m; j++) {
	    a[i][j] = M.a[i][j];
	  }
	}
      }
      return *this;
    }

   /* += operator
   * Usage: M1 += M2; where M1 and M2 are Matrix objects with same dimension
   * Result M1 = M1+M2
   */
    Matrix &operator+=(const Matrix &M) {
      if (m != M.m) {
	std::cerr << "Dimensions mismatch in sum, exiting.." << std::endl;
	exit(1);
      }
      for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	  a[i][j] += M.a[i][j];
	}
      }
      return *this;
    }


    /* Subtract Matrix operator
     * Usage: M1 -= M2; where M1 and M2 are Matrix objects with same dimension
     * Result M1 = M1-M2
     */
    Matrix &operator-=(const Matrix &M) {
      if (m != M.m) {
	std::cerr << "Matrix dimensions mismatch, exiting.." << std::endl;
	exit(1);
      }
      for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	  a[i][j] -= M.a[i][j];
	}
      }
      return *this;
    }

    // Operator *= for matrix multiplication
    const Matrix operator*=(const Matrix &M) {
      if (m != M.m) {
	std::cerr << "Matrix dimensions mismatch, exiting.." << std::endl;
	exit(1);
      }
      double **temp_a = new double *[m];
      for (int i = 0; i < m; i++) {
	temp_a[i] = new double[m];
	for (int j = 0; j < m; j++) {
	  temp_a[i][j] = 0;
	  for (int l = 0; l < m; l++) {
	    temp_a[i][j] += a[i][l] * M.a[l][j];
	  }
	}
      }
      for (int i = 0; i < m; i++) {
	delete[] a[i];
      }
      delete[] a;
      a = temp_a;

      return *this;
    }

    // Operator *= for multiplying matrix with a scalar
    const Matrix operator*=(const double d) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] *= d;
            }
        }
        return *this;

    }

    // Operator * for matrix multiplication
    const Matrix operator*(const Matrix &M) const {
        if (m != M.m) {
	  std::cerr << "Dimensions mismatch, exiting.." << std::endl;
	  exit(1);
        }

        Matrix C(m);
        for (int i = 0; i < m; i++) {
	  for (int j = 0; j < m; j++) {
	    for (int l = 0; l < m; l++) {
	      C.a[i][j] += a[i][l] * M.a[l][j];
	      }
	  }
        }
        return C;
    }

    // FUNCTIONS	:::	:::	:::	:::	:::

    /* Usage: A.fillMatrix(b); where b is an array of 
     * length m*m of doubles
     * Result: A matrix with columns from m elements from b.
     * First column is first m elements, 2nd col is m+1:2m elements
     * etc.
     */
    void fillMatrix(double b[]) {
      for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	  a[i][j] = b[j * m + i];
	}
      }
    }

    /* Usage: A.identity(); where A is Matrix object
     * Result: A identity matrix (1's on diag, 0's rest)
     */
    void identity() {
      for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	  if (i == j) {
	    a[i][j] = 1;
	  } else {
	    a[i][j] = 0;
	  }
	}
      }
    }

    /* Usage: A.printMatrix(); where A is Matrix object.
     * Result: A is printed to the terminal
     */
    void print() {
      std::cout << "[";		// Left bracket
      for (int i = 0; i < m; i++) {
	if (i != 0) {
	  std::cout << " ";	// To align left column
	}
	for (int j = 0; j < m; j++) {
	  std::cout << a[i][j];
	  if (j != m - 1) {
	    std::cout << ", ";	// Separate elements in rows
	  }
	}
	if (i != m - 1) {
	  std::cout << std::endl;	// New row
	}
      }
      std::cout << "]" << std::endl;	// Right bracket 
    }

    /* Matrix infinity norm: norm_inf(A) = max(norm_1(r1),...,norm_1(rm))
     * Usage: x = A.norm(); where A is Matrix object.
     * Result: x is norm_inf(A)
     */
    double norm() {
      double norm = 0, temp_sum;
      for (int i = 0; i < m; i++) {
	temp_sum = 0;
	  for (int j = 0; j < m; j++) {
	    temp_sum += fabs(a[i][j]);
	  }
	  if (temp_sum > norm) {
	    norm = temp_sum;
	  }
      }
      return norm;
    }

    // Returns the size of the matrix
    int sizeMatrix() {
      return m;
    }
};

#endif
