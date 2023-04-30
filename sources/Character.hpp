#ifndef CH_H
#define CH_H

#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel
{

    class Character
    {
    protected:
        Point &_location;
        int _hitPoints;
        string _name;

    public:
        Character(string name, Point &location);
        ~Character();

        bool isAlive();
        double distance(Character &player);
        int hit();
        string getName();
        Point getLocation();
        void print();
    };
}

#endif
