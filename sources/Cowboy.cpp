

#include "Character.hpp"
#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string name, Point &location) : Character(name, location, 110), _numBalls(6)
{
    _Type = 2;
}

Cowboy::~Cowboy()
{
}

void Cowboy::shoot(Character& enemy)
{
    if(enemy.isAlive() && _numBalls > 0 ){
        enemy.hit(10);
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


string Cowboy::Print()
{
}



int Cowboy::get_numBalls(){
    return _numBalls;
}


