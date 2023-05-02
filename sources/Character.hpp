#ifndef CH_H
#define CH_H

#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel
{};


class Character
{
protected:
    string _name;
    Point _location;
    int _hitPoints;

public:
    Character(string name, Point& location, int hit);
    ~Character();

    bool isAlive();
    double distance(Character* player);
    void hit(int num);
    string getName();
    Point getLocation();
    void print();



    //// add by me

    int get_hitPoints();
};


#endif
