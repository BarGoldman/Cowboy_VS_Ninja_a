#include "Character.hpp"
#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(string name, Point &location,int hit ,int speed):Character(name, location, hit),_speed(speed)
{

}

void Ninja::move(Character &enemy)
{
    // _location = Point::moveTowards(_location,enemy.getLocation(),_speed);
}
void Ninja::slash(Character &enemy)
{
    if(this->isAlive() && this->distance(enemy) < 1){
        _hitPoints = _hitPoints - 31;
    }

}



int Ninja::get_speed(){
    return _speed;
}