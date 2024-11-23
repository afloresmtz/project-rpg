#ifndef BLESSEDWEAPON_H
#define BLESSEDWEAPON_H

#include "Weapon.h"

class BlessedWeapon : public Weapon {
private:
    std::string blessing;
    int intensity;
public:
    BlessedWeapon(std::string name, int damage, bool type, std::string blessing, int intensity);

    std::string getBlessing();
    int getIntensity();
};

#endif // BLESSEDWEAPON_H
