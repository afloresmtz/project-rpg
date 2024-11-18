#include "Slime.h"

Slime::Slime(int health, int strength) {
    this->health = health;
    maxHealth = health;
    this->strength = strength;
    magicRes = 20;
    meleeRes = 80;
}

void Slime::split(int pieces) {
    // unable to implement method definition until main.cpp is created and a "battlefield" where all enemy and character objects reside is created
    // without it, there's no way to implement the creation of new objects from a method (at least that I know right now)
    // will be done on next delivery

    // convert into X amount of slimes / create X new Slime objects
    // each slime will have the hp that the big slime had when split
    // slime splits at half health, and only split once
    // example: big slime (100 hp) -> get big slime at 50 hp (or less) -> splits into two slimes, 50 hp each -> when these are gotten to 25 hp, they don't split
}
