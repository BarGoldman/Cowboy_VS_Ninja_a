#ifndef TEAM_H
#define TEAM_H


#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YountNinja.hpp"
#include "TrainedNinja.hpp"


#include <vector>
using namespace std;
namespace ariel
{
};

class Team
{
private:
    Character* _leader;
    vector<Character> _chTeam;
public:
    Team(Character* player);
    virtual ~Team() = default;

    void add(Character* player);
    void attack(Team* other_team);
    int stillAlive();
    void print();



    string get_leader();
};
#endif
