

#include "Character.hpp"
#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110,2), _numBalls(6)
{

}

void Cowboy::shoot(Character* enemy)
{
    if(enemy->isAlive() && _numBalls > 0 ){
        enemy->hit(10);
        _numBalls = _numBalls - 1;
    }
}
bool Cowboy::hasboolets()
{
    return (_numBalls > 0);
}
void Cowboy::reload()
{
    _numBalls = 6 ; 
}


string Cowboy::print()
{
    return "hii";
}



int Cowboy::get_numBalls(){
    return _numBalls;
}


