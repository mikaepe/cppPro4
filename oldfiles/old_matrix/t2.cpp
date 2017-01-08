
// Libraries	::	::	::	::	::	::

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include "matrix.hpp"

using namespace std;


// Function Declarations 	::	::	::	::

Matrix myexp(int m, Matrix A, double tol=1e-10);

// Function Definitions	::	::	::	::	::

/* main function, asks user to input matrix, then
 * calls myexp and compares with given expm from r8
 */
int main(int argc, char *argv[])
{
  cout <<  fixed << setprecision(5);
  int nn = 8;
  double a[nn*nn] = {1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,2,0,2,0,2,0,2,0,-5,0,-5,0,-5,0,-5,0,3,0,3,0,3,0,3,0,1,0,1,0,1,0,1,0,2,0,2,0,2,0,2,0};

  Matrix A(nn); 
  A.fillMatrix(a);		// Own Matrix class
  A.print();

  Matrix myexpA = myexp(nn,A,1e-5);
  cout << "own implementation: exp(A) = " << endl;
  myexpA.print();

  return 0;
}

/* Function myexp is an straight forward implementation of the exponential
 * functions series representation i.e. the McLaurin
 * series without Horners algorithm
 */
Matrix myexp(int m, Matrix A, double tol)
{
    double norm = 1.0;
    Matrix term(m);
    Matrix res(m);
    term.identity();
    res.identity();
    int i = 1;
    while (norm > tol)
    {
        term *= A;
        term *= (1.0 / i);
        norm = term.norm();
        res += term;
        i++;
    }
    cout << "iterations = " << i << endl;
    return res;
}
