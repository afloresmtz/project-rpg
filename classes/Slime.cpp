#include "Slime.h"

Slime::Slime(Stat health, Stat strength) {
    this->health = health;
    this->strength = strength;
    // magicRes = a value to be defined, specific for a slime;
    // meleeRes = a value to be defined, specific for a slime;
}

Slime::split(int pieces) {
    // convert into X amount of slimes / create X new Slime objects
}
