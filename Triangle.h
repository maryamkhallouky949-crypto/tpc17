#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Segment.h"

class Triangle {
private:
    Point a;
    Point b;
    Point c;

public:
    Triangle(Point a, Point b, Point c);

    double perimetre() const;
};

#endif