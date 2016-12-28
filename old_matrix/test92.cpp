// file: test1.cpp

#include <iostream>
#include "matrix.hpp"
#include <cstdlib>

using namespace std;

int main()
{

  Matrix a = Matrix(3);
  
  a.randomize();
  cout << "----print a-----" << endl;
  a.print();

  Matrix b = Matrix(3);
  b = a;
  b.print();
  b += a;
  b.print();

  cout << "norm = " << a.norm() << endl;


  
  return 0;
}

