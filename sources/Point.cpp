#include "Point.hpp"
#include <cmath>
#include <iostream>
using namespace std;


Point::Point(double x_cd , double y_cd):_x(x_cd) , _y(y_cd)
{
}


double Point::distance(Point &point2)
{
    double a = _x - point2._x;
    double b = _y - point2._y;
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