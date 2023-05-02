#ifndef YN_H
#define YN_H
#include "Ninja.hpp"
#include "Point.hpp"
#include <string>
using namespace std;


namespace ariel
{
};

class YoungNinja : public Ninja
{
public:
    YoungNinja(string name,Point& location);
    ~YoungNinja();
};

#endif


