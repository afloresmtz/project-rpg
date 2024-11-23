#ifndef SLIME_H
#define SLIME_H

#include "Enemy.h"
#include "Character.h"

class Slime : public Enemy {
// no private attributes, it shares Enemy's protected attributes
public:
    Slime(int health, Stat strength);

    void scramble();
};

#endif
