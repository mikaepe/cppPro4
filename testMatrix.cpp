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

    return 0;
}
