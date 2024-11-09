#ifndef SLIME_H
#define SLIME_H

#include "Enemy.h"

class Slime : public Enemy {
// no private attributes, it shares the ones with the main class (I think)
public:
    Slime(Stat health, Stat strength);

    void split(int pieces);
};

#endif
