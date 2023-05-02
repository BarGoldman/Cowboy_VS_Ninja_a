#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "doctest.h"

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;

TEST_CASE("Point")
{
    Point a(32.3, 44);
    Point b(1.3, 3.5);
    CHECK_EQ(a.distance(b), b.distance(a));

    Point c(32.3, 44);
    CHECK_EQ(a.distance(c), 0);
}

TEST_CASE("Character")
{
    Point a(32.3, 44);
    Point b(1.3, 3.5);
    Cowboy tom = Cowboy("Tom", a);
    OldNinja lis = OldNinja("Lis", b);
    CHECK_EQ(lis.getName(), "Lis");
    CHECK_EQ(tom.getName(), "Tom");

    int i = 0;
    while (i < 5)
    {
        tom.shoot(lis);
        i++;
    }
    CHECK(lis.get_hitPoints() < 110);
    CHECK_EQ(tom.get_numBalls(), 0);

    tom.reload();
    CHECK_EQ(tom.get_numBalls(), 6);
}

TEST_CASE("2 characters cannot stand in the same place")
{
    Point a(32.3, 44);
    Cowboy tom = Cowboy("Tom", a);

    Point c(32.3, 44);
    CHECK_THROWS(Cowboy("Tai", c));
}

TEST_CASE("The OldNinja is not alive - after 15 shoot ")
{
    Point a(1.2, 3.8);
    Point b(3, 9);
    Cowboy p1 = Cowboy("Kil", a);
    OldNinja p2 = OldNinja("Bil", b);

    int j = 0;
    while (j < 15)
    {
        p1.shoot(p2);
        if (p1.get_numBalls() == 0)
        {
            p1.reload();
        }
        j++;
    }

    CHECK(p2.get_hitPoints() == 0);
    CHECK(p2.isAlive() == false);
}

TEST_CASE("TEAM - A fighter can only be in group 1")
{
    Point a(1.2, 3.8);
    Point b(3, 9);
    Cowboy p1 = Cowboy("Kil", a);
    Team team1(p1);
    Cowboy p2 = Cowboy("Bil", b);
    t.add(p2);

    Cowboy tom = Cowboy("Tom", a);
    Team team2(tom);
    CHECK_THROWS(team2.add(p2));
}

TEST_CASE("TEAM - A group of fighters has 10 participants")
{
    Cowboy p1 = Cowboy("A", Point(6, 5));
    Cowboy p2 = Cowboy("B", Point(7, 5));
    Cowboy p3 = Cowboy("C", Point(69, 50));
    Cowboy p4 = Cowboy("D", Point(60, 50));

    OldNinja p5 = OldNinja("E", Point(6213, 5213));
    OldNinja p6 = OldNinja("F", Point(666, 567));
    OldNinja p7 = OldNinja("G", Point(6313, 5543));
    OldNinja p8 = OldNinja("H", Point(63, 52));
    OldNinja p9 = OldNinja("I", Point(62, 53));
    OldNinja p10 = OldNinja("J", Point(65, 52));

    OldNinja p11 = OldNinja("K", Point(16, 25));

    Team team1(p1);
    CHECK(team1.add(p2));
    CHECK(team1.add(p3));
    CHECK(team1.add(p4));
    CHECK(team1.add(p5));
    CHECK(team1.add(p6));
    CHECK(team1.add(p7));
    CHECK(team1.add(p8));
    CHECK(team1.add(p9));
    CHECK(team1.add(p10));

    CHECK_THROWS(team1.add(p1));
}

TEST_CASE("TEAM - Leader")
{
    Cowboy p1 = Cowboy("A", Point(6, 5));
    Cowboy p2 = Cowboy("B", Point(7, 5));
    Cowboy p3 = Cowboy("C", Point(69, 50));

    Team team2(p1);
    team2.add(p2);
    team2.add(p3);
    CHECK(team2.get_leader == "A");
}
