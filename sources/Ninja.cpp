#include "Character.hpp"
#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(string name, Point location,int hit ,int speed,int type):Character(name, location, hit,type),_speed(speed)
{

}

void Ninja::move(Character* enemy)
{
    
}
void Ninja::slash(Character* enemy)
{
    if(this->isAlive() && this->distance(enemy) < 1){
        set_hitPoints(13);
    }

}



int Ninja::get_speed(){
    return _speed;
}