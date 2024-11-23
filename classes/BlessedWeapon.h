#ifndef BLESSEDWEAPON_H
#define BLESSEDWEAPON_H

#include "Weapon.h"

class BlessedWeapon : public Weapon {  // inheritance from Weapon
private:
    // private subclass attributes
    std::string blessing;
    int intensity;
public:
    // constructor
    BlessedWeapon(std::string name, int damage, bool type, std::string blessing, int intensity);

    // getter for subclass attributes
    std::string getBlessing();
    int getIntensity();
};

#endif // BLESSEDWEAPON_H
