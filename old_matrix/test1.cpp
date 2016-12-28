// file: test1.cpp

#include <iostream>
#include "matrix.hpp"
#include <cstdlib>

using namespace std;

int main()
{

  Matrix a = Matrix(3);
  Matrix a2 = Matrix(3);
  
  
  
  a.randomize();
  cout << "----print a-----" << endl;
  a.print();

  cout << "enter integer" << endl;
  int k;
  cin >> k;
  srand(k);

  a2.randomize();
  cout << "---- print a2-----" << endl;
  a2.print();


  a*=a2;
  cout << "---- print a*a2 -----" << endl;
  a.print();

  
  return 0;
}

