#ifndef SKELETON_H
#define SKELETON_H

#include "Enemy.h"

class Skeleton : public Enemy {
// no private attributes, it shares the ones with the main class (I think)
public:
    Skeleton(Stat health, Stat strength);

    void regenerate();
};

#endif
