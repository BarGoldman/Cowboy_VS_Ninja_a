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
    // Point(const Point& other){
    //     this->_x = other._x;
    //     this->_y = other._y;
    // }
    // Point(){
    //     this->_x = 0;
    //     this->_y = 0; 
    //     }
    Point(double x_cd, double y_cd);

    double distance(Point &point2);
    void print();

    Point moveTowards(Point &source, Point &target, double dis);
};

#endif
