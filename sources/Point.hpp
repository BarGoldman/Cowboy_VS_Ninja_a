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
    Point(double x_cd, double y_cd);
    // ~Point() = default;

    double distance(Point &point2);
    void print();

    Point moveTowards(Point &source, Point &target, double dis);
};

#endif
