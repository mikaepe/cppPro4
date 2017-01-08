// file: tstShared_ptr.cpp

#include "point.hpp"
#include "corner.hpp"

#include <memory>

using namespace std;

int main(int argc, char *argv[])
{
  shared_ptr<Point> c = make_shared<Point>(1.0,2.0);

  Corner a1 = Corner(1.0,0.0,c);
  a1.print();
  Corner a2 = Corner(1.0,1.5708,c);
  a2.print();
  Corner a3 = Corner(1.0,3.1416,c);
  a3.print();



  return 0;
}
