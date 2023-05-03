#include "Team.hpp"

Team::Team(Character* player) : _leader(player)
{
    add(player);
}


void Team::add(Character* player)
{
    if(_chTeam.size() == 10){
        throw("team of 10");
    }
    // _chTeam.pop_back(player);
}
void Team::attack(Team *other_team)
{
}
int Team::stillAlive()
{
    return 0;
}
void Team::print()
{
}


string Team::get_leader(){
    return _leader->getName();
}