#include "Character.hpp"
#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(string name, Point location,int hit ,int speed):Character(name, location, hit,1),_speed(speed)
{

}

void Ninja::move(Character* enemy)
{
    
}
void Ninja::slash(Character* enemy)
{
    if(isAlive() && this->distance(enemy) < 1){
        enemy->hit(40);
    }

}

int Ninja::get_speed(){
    return _speed;
}