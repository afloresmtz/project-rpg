#ifndef SKELETON_H
#define SKELETON_H

#include "Enemy.h"

class Skeleton : public Enemy {
// no private attributes, it shares Enemy's protected attributes
public:
    Skeleton(int health, int strength);

    void regenerate();
};

#endif
