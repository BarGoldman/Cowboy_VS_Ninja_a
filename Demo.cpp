/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;

int main()
{
   Point a(32.3, 44), b(1.3, 3.5);
   assert(a.distance(b) == b.distance(a));

   Cowboy *tom = new Cowboy("Tom", a);
   OldNinja *sushi = new OldNinja("sushi", b);
   YoungNinja *yogi = new YoungNinja("Yogi", Point(64, 57));
   TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12, 81));
   
   tom->shoot(sushi);
   // cout << tom->print() << endl;

   sushi->move(tom);
   sushi->slash(tom);

   Team ta(tom);
   ta.add(yogi);

   // Team b(&tom); should throw tom is already in team a

   Team tb(sushi);
   tb.add(hikari);

   while (ta.stillAlive() > 0 && tb.stillAlive() > 0)
   {
      ta.attack(&tb);
      tb.attack(&ta);
      ta.print();
      tb.print();
   }

   if (ta.stillAlive() > 0)
      cout << "winner is a" << endl;
   else
      cout << "winner is b" << endl;

   // Prevent memory leaks
   delete tom;
   delete sushi;
   delete yogi;
   delete hikari;

   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.
}
