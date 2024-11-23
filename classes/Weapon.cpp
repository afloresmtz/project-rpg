#include "Weapon.h"

// constructor
Weapon::Weapon(string name, int damage, bool type) {
    this->name = name;
    this->damage = damage;
    this->type = type;
}

// getters for object attributes
string Weapon::getName() {
    return name;
}

int Weapon::getDamage() {
    return damage;
}

bool Weapon::getType() {
    return type;
}
