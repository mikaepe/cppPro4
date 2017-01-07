// file: testDomain.cpp

#include <iostream>
#include <memory>
#include <cmath>		// for sin and cos
#include "curvebase.hpp"
#include "xline.hpp"
#include "yline.hpp"
#include "xquad.hpp"
#include "fxcurve.hpp"
#include "domain.hpp"
#include "gfctn.hpp"
#include "point.hpp"		// f defined on points

using namespace std;

// function for testing the classes (as specified in lab instructions)
inline double f(Point p) {
  return sin((p.X()*p.X()*0.01))*cos(p.X()*0.1) + p.Y();
}

int main(int argc, char *argv[])
{


  /*
  shared_ptr<xQuad> a = make_shared<xQuad>(-.25,0,.25,-1,1);
  shared_ptr<yLine> b = make_shared<yLine>(0,1,1);
  shared_ptr<xLine> c = make_shared<xLine>(-1,1,1);
  shared_ptr<yLine> d = make_shared<yLine>(0,1,-1);

  */

  shared_ptr<fxCurve> a = make_shared<fxCurve>(-10.0,5.0);
  shared_ptr<yLine> b = make_shared<yLine>(0.0,3.0,5.0);
  shared_ptr<xLine> c = make_shared<xLine>(-10.0,5.0,3.0);
  shared_ptr<yLine> d = make_shared<yLine>(0.0,3.0,-10.0);


  

  shared_ptr<Domain> grid = make_shared<Domain>(a,b,c,d);
  grid->grid_generation(50,20);
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

  Gfctn DDyU2 = U.DD0y2();
  cout << "2nd derivative (non const. h, wrt y)" << endl;
  DDyU2.print();
  
  Gfctn Laplace = U.laplace();
  cout << "Laplace: " << endl;
  Laplace.print();

  return 0; 	// Great Success
}
  
