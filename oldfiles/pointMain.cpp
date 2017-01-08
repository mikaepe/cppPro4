// file: pMain.cpp

#include <iostream>
#include "point.hpp"

int main()
{
  Point p = Point(0.3,2.7);
  p.print();

  Point q = p;		// Uses the copy constructor
  q.print();

  Point r;
  r = p;		// Uses the copy-assignment constructor
  r.print();

  Point p2 = Point(1.0,1.0);
  cout << "p2 = "; p2.print();
  cout << "p2 = -p gives p2 = ";
  p2 = -p; 
  p2.print();

  cout << "r.print() = "; r.print();
  cout << "r = " << r << endl;
  cout << endl << "--------------------------------" << endl;

  Point P;
  cout << "P = " << P << endl;
  Point Q = Point(2.1,3.1);
  cout << "Q = " << Q << endl;
  P = -Q;
  cout << "P = -Q gives P = " << P << endl;
  P.zero();
  cout << "P = " << P << endl;
  P -= Q;
  cout << "P -= Q gives P = " << P << endl;

  Point R;
  cout << "R = " << R << endl;
  cout << "P = " << P << endl;
  cout << "Q = " << Q << endl;
  R = P-Q;
  cout << "R = P-Q gives R = " << R << endl;
  cout << "now, P = " << P << endl;
  




  return 0;
}
