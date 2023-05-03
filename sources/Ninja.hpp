#ifndef N_H
#define N_H

#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
using namespace std;

namespace ariel
{
};

class Ninja : public Character
{
private:
    int _speed;


public:
    Ninja(string name, Point location,int hit ,int speed);
    ~Ninja();

    void move(Character* enemy);
    void slash(Character* enemy);


    /// 
    int get_speed();
};
#endif
