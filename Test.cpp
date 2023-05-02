#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "doctest.h"

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


TEST_CASE("Point"){
    Point a(32.3,44);
    Point b(1.3,3.5);
    CHECK_EQ(a.distance(b) , b.distance(a));

    Point c(32.3,44);
    CHECK_EQ(a.distance(c) , 0);
}

TEST_CASE("Character"){
    Point a(32.3,44);
    Point b(1.3,3.5);
    Cowboy tom =  Cowboy("Tom", a);
    OldNinja lis =  OldNinja("Lis", b);
    CHECK_EQ(lis.getName() , "Lis");
    CHECK_EQ(tom.getName() , "Tom");


    int  i = 0 ;
    while(i < 5){
        tom.shoot(lis);
        i++;
    }
    CHECK(lis.get_hitPoints() < 110);
    CHECK_EQ(tom.get_numBalls() , 0);

    tom.reload();
    CHECK_EQ(tom.get_numBalls() , 6);

}

TEST_CASE("2 characters cannot stand in the same place"){
    Point a(32.3,44);
    Cowboy tom =  Cowboy("Tom", a);

    Point c(32.3,44);
    CHECK_THROWS(Cowboy("Tai", c));
}


TEST_CASE("The OldNinja is not alive - after 15 shoot "){
    Point a(1.2,3.8);
    Point b(3,9);
    Cowboy p1 =  Cowboy("Kil", a);
    OldNinja p2 =  OldNinja("Bil", b);

    int j = 0;
    while(j < 15 ){
        p1.shoot(p2);
        if(p1.get_numBalls() == 0){
            p1.reload();
        }
        j++;
    }

    CHECK(p2.get_hitPoints() == 0);
    CHECK(p2.isAlive() == false);
}

