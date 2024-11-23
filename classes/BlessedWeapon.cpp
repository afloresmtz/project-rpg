#include "BlessedWeapon.h"
#include <iostream>

// Constructor
BlessedWeapon::BlessedWeapon(std::string name, int damage, bool type, std::string blessing, int intensity)
    : Weapon(name, damage, type), blessing(blessing), intensity(intensity) {}

// Method to apply the blessing effect
std::string BlessedWeapon::getBlessing() {
    return blessing;
}
int BlessedWeapon::getIntensity() {
    return intensity;
}
