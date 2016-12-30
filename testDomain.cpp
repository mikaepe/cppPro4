// file: testDomain.cpp

#include <iostream>
#include <memory>
#include "curvebase.hpp"
#include "xline.hpp"
#include "yline.hpp"
#include "xquad.hpp"
#include "domain.hpp"

using namespace std;

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

  Domain D = Domain(a,b,c,d);
  D.grid_generation(10,5);

  // D.print();
  D.writeFile();

  cout << "D.xsize() = " << D.xsize() << endl;
  cout << "D.ysize() = " << D.ysize() << endl;
  cout << "D.gridValid() = " << D.gridValid() << endl;


  return 0; 	// Great Success
}
  
