#include "Slime.h"

Slime::Slime(int health, int strength) {
    this->health = health;
    maxHealth = health;
    this->strength = strength;
    magicRes = 20;
    meleeRes = 80;
}

void Slime::split(int pieces) {
    // convert into X amount of slimes / create X new Slime objects
}
