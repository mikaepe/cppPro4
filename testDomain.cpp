// file: testDomain.cpp

#include <iostream>
#include <memory>
#include <cmath>		// for sin and cos
#include "curvebase.hpp"
#include "xline.hpp"
#include "yline.hpp"
#include "xquad.hpp"
#include "domain.hpp"
#include "gfctn.hpp"
#include "point.hpp"		// f defined on points

using namespace std;

inline double f(Point p) {
  return sin((p.X()*p.X()*0.01))*cos(p.X()*0.1) + p.Y();
}

int main(int argc, char *argv[])
{

/*
  xQuad a = xQuad(-.25,0,.25,-1,1);
  yLine b = yLine(0,1,1);
  xLine c = xLine(-1,1,1);
  yLine d = yLine(0,1,-1);
*/

  shared_ptr<xQuad> a = make_shared<xQuad>(-.25,0,.25,-1,1);
  shared_ptr<yLine> b = make_shared<yLine>(0,1,1);
  shared_ptr<xLine> c = make_shared<xLine>(-1,1,1);
  shared_ptr<yLine> d = make_shared<yLine>(0,1,-1);


  shared_ptr<Domain> grid = make_shared<Domain>(a,b,c,d);
  grid->grid_generation(6,3);
  cout << "x-size = " << grid->xsize() << endl;
  cout << "y-size = " << grid->ysize() << endl;
  grid->writeFile();
  Gfctn U = Gfctn(grid);
  U.setFunction(&f);
  U.print();

  
  Gfctn DxU = U.D0x();                
  cout << "derivative: " << endl;
  DxU.print();

  Gfctn DDxU = U.DD0x();
  cout << "2nd derivative: " << endl;
  DDxU.print();

  Gfctn DDxU2 = U.DD0x2();
  cout << "2nd derivative (non const. h) " << endl;
  DDxU2.print();

  return 0; 	// Great Success
}
  
