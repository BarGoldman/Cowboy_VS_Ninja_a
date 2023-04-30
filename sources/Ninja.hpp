#ifndef N_H
#define N_H

#include "Character.hpp"
using namespace std;

namespace ariel
{
};

class Ninja : public Character
{
private:
    int _speed;
public:
    Ninja(/* args */);
    ~Ninja();

    void move(Character* enemy);
    void slash(Character* enemy);
};
#endif

// Ninja::Ninja(/* args */)
// {
// }

// Ninja::~Ninja()
// {
// }
