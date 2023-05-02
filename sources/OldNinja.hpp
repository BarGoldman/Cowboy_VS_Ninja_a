#ifndef ON_H
#define ON_H

#include "Ninja.hpp"
#include "Character.hpp"

namespace ariel
{
};

class OldNinja : public Ninja
{
private:
    /* data */
public:
    OldNinja(string name, Point &location);
    ~OldNinja();
};
#endif

