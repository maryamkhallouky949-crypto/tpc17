#include "Point3D.h"
#include <iostream>
#include <cmath>

using namespace std;

Point3D::Point3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point3D::afficher() const {
    cout << "Point : (" << x << ", "
         << y << ", " << z << ")" << endl;
}

double Point3D::distanceOrigine() const {
    return sqrt(x * x + y * y + z * z);
}