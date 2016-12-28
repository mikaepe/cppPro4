// file: test1.cpp

#include <iostream>
#include "matrix.hpp"

using namespace std;

int printShiz(int k);

int main()
{

  int k = 1;

  Matrix asd = Matrix(3);
  asd.randomize();
  k = printShiz(k);
  asd.print();

  double lambda = 2.0;
  asd *= lambda;
  k = printShiz(k);
  asd.print();

  Matrix d = Matrix();
  cout << "- - - - - - d = asd - - - - - - " << endl;
  cout << "------- d.size = " << d.sizeMatrix() << endl;
  d = asd;
  k = printShiz(k);
  d.print();

  Matrix d2 = Matrix(2);
  double dd[4] = {1,2,3,4};
  d2.fillMatrix(dd);
  d2.print();

  cout << "- - - - - - d = d2 - - - - - - - " << endl;
  d = d2;
  k = printShiz(k);
  d.print();

  cout << "- - - - - - d2 = d2 - - - - - - " << endl;
  d2 = d2;
  d.print();


  return 0;
}

int printShiz(int k)
{
  cout << "print " << k << ":" << endl;
  return k+1;
}
