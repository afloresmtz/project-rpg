#include "Skeleton.h"

Skeleton::Skeleton(Stat health, Stat strength) {
    this->health = health;
    this->strength = strength;
    // magicRes = a value to be defined, specific for a skeleton;
    // meleeRes = a value to be defined, specific for a skeleton;

}

void Skeleton::regenerate() {
    // when death: counter = 0
    // while dead:
    // if (counter < 3):
    // break;
    // else:
    // remove dead; heal to half hp
}
