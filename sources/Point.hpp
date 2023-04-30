#ifndef POINT_H
#define POINT_H

using namespace std;
namespace ariel
{
};

class Point
{
private:
    double _x;
    double _y;

public:
    Point(double x , double y);
    ~Point();


    double distance(Point& p);
    void print();

    Point moveTowards(Point& source , Point& target , double dis);
};

#endif

