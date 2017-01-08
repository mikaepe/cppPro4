// file: main1.cpp

#include <iostream>
#include <memory>
#include <cmath>		// for sin and cos
#include "xline.hpp"
#include "yline.hpp"
#include "fxcurve.hpp"
#include "domain.hpp"
#include "gfctn.hpp"

using namespace std;

// function for testing the classes (as specified in lab instructions)
inline double f(Point p) {
  return sin((p.X()*p.X()*0.01))*cos(p.X()*0.1) + p.Y();
}

int main(int argc, char *argv[])
{

  // the boundary curves to the domain
  shared_ptr<fxCurve> a = make_shared<fxCurve>(-10.0,5.0);
  shared_ptr<yLine> b = make_shared<yLine>(0.0,3.0,5.0);
  shared_ptr<xLine> c = make_shared<xLine>(-10.0,5.0,3.0);
  shared_ptr<yLine> d = make_shared<yLine>(0.0,3.0,-10.0);

  // generating a grid on the domain and writing it to bin file
  shared_ptr<Domain> grid = make_shared<Domain>(a,b,c,d);
  grid->grid_generation(50,20);
  grid->writeFile("gridOut.bin");

  // grid function using function f
  Gfctn U = Gfctn(grid);
  U.setFunction(&f);

  // derivative wrt x
  Gfctn DxU = U.D0x();                
  cout << "derivative x" << endl;
  DxU.writeFile("DxOut.bin");

  // derivative wrt y
  Gfctn DyU = U.D0y();
  cout << "derivative y" << endl;
  DyU.writeFile("DyOut.bin");

  // laplace operator
  Gfctn Laplace = U.laplace();
  cout << "Laplace" << endl;
  Laplace.writeFile("laplaceOut.bin");

  return 0;
}
  
