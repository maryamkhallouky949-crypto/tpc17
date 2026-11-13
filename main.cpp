#include <iostream>
#include "Matrix.h"

using namespace std;
int main() {
    Matrix<int, 2, 2> A{
        {1, 2},
        {3, 4}
    };
    Matrix<int, 2, 2> B{
        {5, 6},
        {7, 8}
    };
    cout << "Matrice A :" << endl;
    cout << A << endl;
    cout << "Matrice B :" << endl;
    cout << B << endl;
    Matrix<int, 2, 2> C = A + B;
    cout << "Addition A + B :" << endl;
    cout << C << endl;
    Matrix<int, 2, 2> D = A * B;
    cout << "Multiplication A * B :" << endl;
    cout << D << endl;
    Matrix<double, 3, 3> E{
        {1.5, 2.0, 3.0},
        {4.0, 5.5, 6.0},
        {7.0, 8.0, 9.5}
    };

    cout << "Matrice double E :" << endl;
    cout << E << endl;

    cout << "Element E[0][1] : "
         << E.at(0, 1) << endl;

    return 0;
}