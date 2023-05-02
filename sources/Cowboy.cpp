

#include "Character.hpp"
#include "Cowboy.hpp"
using namespace ariel;


Cowboy::Cowboy(string name, Point &location):Character(name,location,110)
{
    _numBalls = 6;
}

Cowboy::~Cowboy()
{
}
