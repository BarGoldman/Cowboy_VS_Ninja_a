#ifndef CH_H
#define CH_H

#include "Point.hpp"
// #include "Ninja.hpp"
// #include "Cowboy.hpp"
// #include "OldNinja.hpp"
#include <string>
using namespace std;
namespace ariel
{


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
    double distance(Character& player);
    int hit();
    string getName();
    Point getLocation();
    void print();
};
}

#endif
