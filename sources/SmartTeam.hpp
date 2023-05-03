#ifndef ST_H
#define ST_H

#include "Team.hpp"

class SmartTeam :public Team
{
private:
    /* data */
public:
    SmartTeam(Character* player);
    ~SmartTeam();


    void print();
};
#endif
