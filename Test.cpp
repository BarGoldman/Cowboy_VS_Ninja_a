#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "doctest.h"

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;

TEST_CASE("Point - simpel test")
{
    Point a(32.3, 44);
    Point b(1.3, 3.5);
    CHECK_EQ(a.distance(b), b.distance(a));

    Point c(32.3, 44);
    CHECK_EQ(a.distance(c), 0);

    Point d(32.5, 44);
    CHECK(a.distance(b) < d.distance(b));
}

TEST_CASE("creating a negative point")
{
    CHECK_NOTHROW(Point(-2.555 , -6.84));
}

TEST_CASE("Point - moveTowards - You can't move with a negative size")
{
    double move = -3;
    Point a(32.3, 44);
    Point b(1.3, 3.5);
    CHECK_THROWS(a.moveTowards(a,b,move));
}

TEST_CASE("Character - Simpel test")
{
    Point a(32.3, 44);
    Point b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *lis = new OldNinja("Lis", b);
    CHECK(tom->isAlive() == true);
    CHECK(lis->isAlive() == true);
    CHECK_EQ(lis->getName(), "Lis");
    CHECK_EQ(tom->getName(), "Tom");
    CHECK_EQ(lis->get_hitPoints(), 150);

    int i = 0;
    while (i < 6)
    {
        tom->shoot(lis);
        i++;
    }
    CHECK_EQ(lis->get_hitPoints(), 90);
    CHECK_EQ(tom->get_hitPoints(), 110);
    CHECK_EQ(tom->get_numBalls(), 0);
    CHECK_EQ(tom->hasboolets() , false);

    tom->reload();
    CHECK_EQ(tom->get_numBalls(), 6);
    CHECK_EQ(tom->hasboolets() , true);
}

TEST_CASE("shoot when the ninja is dead && ninja dead try slash cowboy "){
    OldNinja *p1 = new OldNinja("A", Point(0.2, 5));
    Cowboy *tom = new Cowboy("Tom", Point(1,5));
    while (p1->isAlive())
    {
        tom->shoot(p1);
        if(tom->get_numBalls() == 0){
            tom->reload();
        }
    }
    CHECK_THROWS(tom->shoot(p1));
    CHECK_THROWS(p1->slash(tom));
    CHECK(tom->get_hitPoints() == 110);
}

TEST_CASE("slash cowboy until he dead && cowboy dead try to shoot"){
    OldNinja *p1 = new OldNinja("A", Point(0.2, 5));
    Cowboy *tom = new Cowboy("Tom", Point(1,5));
    while (tom->isAlive())
    {
        p1->slash(tom);
    }
    CHECK_THROWS(tom->shoot(p1));
    CHECK_THROWS(p1->slash(tom));
}

TEST_CASE("Character - distance")
{
    OldNinja *p1 = new OldNinja("A", Point(0, 5));
    YountNinja *p2 = new YountNinja("B", Point(9, 5));
    TrainedNinja *p3 = new TrainedNinja("C", Point(4, 5));
    TrainedNinja *p4 = new TrainedNinja("C", Point(5, 5));


    p1->move(p4);
    p2->move(p4);
    Point p = p1->getLocation();
    Point t = p2->getLocation();
    CHECK(p.distance(t)==1);
}

TEST_CASE("cowboy dead cant do reload")
{
    OldNinja *p1 = new OldNinja("A", Point(0.2, 5));
    Cowboy *tom = new Cowboy("Tom", Point(1,5));
    while (tom->isAlive())
    {
        p1->slash(tom);
    }
    CHECK_THROWS(tom->reload());
}

TEST_CASE("cowboy try to shoot when his balls over")
{
    OldNinja *p1 = new OldNinja("A", Point(2,1));
    Cowboy *tom = new Cowboy("Tom", Point(2,2));
    int i = 0;
    while (i < 6)
    {
        tom->shoot(p1);
        i++;
    }
    CHECK(tom->hasboolets() == false);
    tom->shoot(p1);
    CHECK(p1->get_hitPoints() == 90);
}

TEST_CASE("cowboy cant shoot him self")
{
    Cowboy *tom = new Cowboy("Tom", Point(2,2));
    CHECK_THROWS(tom->shoot(tom));
}

TEST_CASE("ninja cant slash him self")
{
    OldNinja *p1 = new OldNinja("A", Point(0, 5));
    CHECK_THROWS(p1->slash(p1));
}

TEST_CASE(" Ninja can slash eneamy - less than a meter away")
{
    OldNinja *p1 =new OldNinja("A", Point(0.2, 5));
    YountNinja *p2 = new YountNinja("B", Point(10, 5));

    Cowboy *p4 =new Cowboy("D", Point(1, 5));

    CHECK_NOTHROW(p1->slash(p4));
    CHECK(p4->get_hitPoints() == 70);

    CHECK_NOTHROW(p1->slash(p2));
    CHECK(p2->get_hitPoints() == 100);
}

TEST_CASE("Ninja tries to slash Cowboy, but the distance between them is a meter"){
    OldNinja *p1 = new OldNinja("A", Point(2,5));
    Cowboy *tom = new Cowboy("Tom", Point(1,5));
    CHECK_NOTHROW(p1->slash(tom));
    CHECK(tom->get_hitPoints()== 110);
}

TEST_CASE(" Ninja can slash cowboy 3 time than he dead")
{
    OldNinja *p1 =new OldNinja("A", Point(0.2, 5));
    Cowboy *p2 =new Cowboy("D", Point(1, 5));

    int count = 0;
    while (p2->isAlive())
    {
        p1->slash(p2);
        count++;
    }
    CHECK(count == 3);
}

TEST_CASE("The OldNinja is not alive - after 15 shoot ")
{
    Point a(1.2, 3.8);
    Point b(3, 9);
    Cowboy *p1 = new Cowboy("Kil", a);
    OldNinja *p2 =new OldNinja("Bil", b);

    int j = 0;
    while (j < 15)
    {
        p1->shoot(p2);
        if (p1->get_numBalls() == 0)
        {
            p1->reload();
        }
        j++;
    }
    CHECK(p2->isAlive() == false);
}


TEST_CASE("TEAM - A fighter can only be in group 1")
{
    Point a(1.2, 3.8);
    Point b(3, 9);
    Cowboy *p1 =new Cowboy("Kil", a);
    Team team1(p1);
    Cowboy *p2 =new Cowboy("Bil", b);
    team1.add(p2);

    Cowboy *tom =new Cowboy("Tom", a);
    Team team2(tom);
    CHECK_THROWS(team2.add(p2));
}

TEST_CASE("TEAM - A player will register for the team only once")
{
    Point a(1.2, 3.8);
    Point b(3, 9);
    Cowboy *p1 =new Cowboy("Kil", a);
    Team team1(p1);
    Cowboy *p2 =new Cowboy("Bil", b);
    team1.add(p2);
    Cowboy *tom =new Cowboy("Tom", a);
    team1.add(tom);
    CHECK_THROWS(team1.add(tom));
}

TEST_CASE("TEAM - A group of fighters has 10 participants")
{
    Cowboy *p1 =new Cowboy("A", Point(6, 5));
    Cowboy *p2 =new Cowboy("B", Point(7, 5));
    Cowboy *p3 = new Cowboy("C", Point(69, 50));
    Cowboy *p4 = new Cowboy("D", Point(60, 50));

    TrainedNinja *p5 =new TrainedNinja("E", Point(6213, 5213));
    OldNinja *p6 = new OldNinja("F", Point(666, 567));
    YountNinja *p7 = new YountNinja("G", Point(6313, 5543));
    TrainedNinja *p8 = new TrainedNinja("H", Point(63, 52));
    OldNinja *p9 = new OldNinja("I", Point(62, 53));
    YountNinja *p10 = new YountNinja("J", Point(65, 52));

    OldNinja *p11 = new OldNinja("K", Point(16, 25));

    Team team1(p1);
    CHECK_NOTHROW(team1.add(p2));
    CHECK_NOTHROW(team1.add(p3));
    CHECK_NOTHROW(team1.add(p4));
    CHECK_NOTHROW(team1.add(p5));
    CHECK_NOTHROW(team1.add(p6));
    CHECK_NOTHROW(team1.add(p7));
    CHECK_NOTHROW(team1.add(p8));
    CHECK_NOTHROW(team1.add(p9));
    CHECK_NOTHROW(team1.add(p10));

    CHECK_THROWS(team1.add(p11));
}

TEST_CASE("TEAM - Leader")
{
    Cowboy *p1 =new Cowboy("A", Point(6, 5));
    Cowboy *p2 =new Cowboy("B", Point(7, 5));
    Cowboy *p3 =new Cowboy("C", Point(69, 50));

    Team team2(p1);
    team2.add(p2);
    team2.add(p3);
    CHECK(team2.get_leader() == "A");
}