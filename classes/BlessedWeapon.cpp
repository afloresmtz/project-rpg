#include "BlessedWeapon.h"
#include <iostream>

// constructor (borrows from Weapon constructor)
BlessedWeapon::BlessedWeapon(std::string name, int damage, bool type, std::string blessing, int intensity)
    : Weapon(name, damage, type), blessing(blessing), intensity(intensity) {}

// getters for subclass attributes
std::string BlessedWeapon::getBlessing() {
    return blessing;
}
int BlessedWeapon::getIntensity() {
    return intensity;
}
