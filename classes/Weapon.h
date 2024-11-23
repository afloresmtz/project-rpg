#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string name;
    int damage;
    bool type;
public:
    Weapon(std::string name, int damage, bool type);

    std::string getName();
    int getDamage();
    bool getType();
};


#endif
