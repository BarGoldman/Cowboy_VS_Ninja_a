#ifndef COWBOY_H
#define COWBOY_H

#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include <string>
using namespace std;
using namespace ariel;


class Cowboy : public Character
{
private:
    int _numBalls;

public:
    Cowboy(string name, Point &location);
    ~Cowboy();

    void shoot(Character& enemy);
    bool hasboolets();
    void reload();
    string Print();


    //// 
    int get_numBalls();
};

#endif