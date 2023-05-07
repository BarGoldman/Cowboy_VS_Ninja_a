#ifndef CH_H
#define CH_H

#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel
{};


class Character
{
private:
    string _name;
    Point _location;
    int _hitPoints;

    int _type; // 1 - for Ninja  , 2 - for Cowboy

public:
    // Character(const Character& other){
    //     this->_name = other._name;
    //     this->_hitPoints = other._hitPoints;
    //     this->_location = other._location;
    // }
    Character(string name, Point location, int hit,int type);
    virtual ~Character(){}

    bool isAlive();
    double distance(Character* player);
    void hit(int num);
    string getName();
    Point getLocation();
    virtual string print() const;






    //// add by me

    int get_hitPoints();
    void set_hitPoints(int num);
};


#endif
