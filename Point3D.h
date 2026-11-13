
#ifndef POINT3D_H
#define POINT3D_H

class Point3D {
private:
    double x;
    double y;
    double z;

public:
    Point3D(double x, double y, double z);

    void afficher() const;
    double distanceOrigine() const;
};

#endif