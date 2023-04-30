#ifndef TEAM_H
#define TEAM_H


#include "Character.hpp"
#include <vector>
using namespace std;
namespace ariel
{
};

class Team
{
private:
    Character& _leader;
    vector<Character> _chTeam;
public:
    Team(/* args */);
    ~Team();

    void add(Character* player);
    void attack(Team t);
    int stillAlive();
    void print();
};
#endif
