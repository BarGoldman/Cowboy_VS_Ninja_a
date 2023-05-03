#ifndef T2_H
#define T2_H

#include "Team.hpp"

class Team2 : public Team
{
private:
    /* data */
public:
    Team2(Character* player):Team(player){}

    void print();
};
#endif

