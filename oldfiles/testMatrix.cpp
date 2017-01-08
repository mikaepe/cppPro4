#include <iostream>
#include "matrix.hpp"

using namespace std;

int main(){
    Matrix m = Matrix(2,4);
    m.randomize();
    m.print();
    Matrix m2 = Matrix(2,4);
    m2.randomize();
    m2.print();
    m2 += m;
    m2.print();
    m2 *= 0.5;
    m2.print();

    Matrix m3 = m2;
    m3.print();

    cout << "Col size: " << m2.colSizeMatrix() << endl;
    cout << "Row size: " << m2.rowSizeMatrix() << endl;

    m3.identity();
    Matrix m4 = Matrix(2,2);
    m4.identity();
    m4.print();

    cout << "------------------" << endl;

    cout << "m3 = "; m3.print();
    cout << "m  = "; m.print();
    cout << "m2 = "; m2.print();
    cout << "m3 = m + m2 gives ";
    m3 = m + m2;
    m3.print();
    cout << "---------------" << endl;
    cout << "m3(0,0) = m(0,0) + m2(0,0) gives";
    m3(0,0) = m.get(0,0) + m2.get(0,0);
    cout << m3.get(0,0) << endl;


    return 0;
}
