#include "Point.hpp"
#include <cmath>
#include <iostream>
using namespace std;


Point::Point(double x , double y):_x(x) , _y(y)
{
}


double Point::distance(Point &p)
{
    double a = _x - p._x;
    double b = _y - p._y;
    return sqrt(pow(a, 2) + pow(b, 2));
}
void Point::print()
{
    cout << '(' << _x << ',' << _y << ')' << endl;
}

Point Point::moveTowards(Point &source, Point &target, double dis)
{
    // double temp = source.distance(target);
    return Point(1,2);

}