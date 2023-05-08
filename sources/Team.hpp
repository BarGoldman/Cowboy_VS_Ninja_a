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
    vector<Character* > _chTeam;
    Character* _leader;
public:
    // Team(const Team& other){
    //     this->_chTeam = other._chTeam;
    // }
    Team(Character* player);
    // virtual ~Team(){}
    virtual ~Team(){
        for(vector<Character* >::size_type i = 0; i< _chTeam.size() ; i++){
            if(_chTeam[i] != NULL){
                delete _chTeam[i];
            }
        }
    };

    void add(Character* player);
    void attack(Team* other_team);
    int stillAlive();
    virtual void print() const;



    string get_leader();
};
#endif
