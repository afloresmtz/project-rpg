#include "Skeleton.h"

Skeleton::Skeleton(int health, int strength) {
    this->health = health;
    maxHealth = health;
    this->strength = strength;
    magicRes = 25;
    meleeRes = 75;

}

void Skeleton::regenerate() {
    // when death: counter = 0
    // while dead:
    // if (counter < 3):
    // break;
    // else:
    // remove dead; heal to half hp
}
