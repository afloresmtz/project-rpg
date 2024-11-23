#ifndef SKELETON_H
#define SKELETON_H

#include "Enemy.h"

class Skeleton : public Enemy {
private:
    bool regenerated;
public:
    Skeleton(int health, int strength);

    void regenerate();
};

#endif
