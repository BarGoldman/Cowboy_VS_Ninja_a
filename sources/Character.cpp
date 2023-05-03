#include "Character.hpp"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

Character::Character(string name, Point location, int hit,int type) : _name(name), _location(location), _hitPoints(hit),_type(type)
{
}


bool Character::isAlive()
{
    return (_hitPoints > 0);
}

double Character::distance(Character* player)
{
    return _location.distance(player->_location);
}

void Character::hit(int num)
{
    _hitPoints = _hitPoints - num;
}

string Character::getName()
{
    return _name;
}

Point Character::getLocation()
{
    return _location;
}

string Character::print()
{
    // if(isAlive()){
    //     cout << "Name: " << _name << "Num Of Hit Point: " << _hitPoints << "Location: " << endl;
    // }
    return "h";
    
}



//////

int Character::get_hitPoints(){
    return _hitPoints;
}