#ifndef POINT_H
#define POINT_H

namespace ariel
{
};

class Point
{
private:
    double _x;
    double _y;

public:
    Point(double x, double y);

    double distance(Point &p);
    void print();

    Point moveTowards(Point &source, Point &target, double dis);
};

#endif
