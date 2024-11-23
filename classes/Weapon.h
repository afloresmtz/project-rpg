#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
protected:
    // protected attributes
    std::string name;
    int damage;
    bool type;
public:
    // constructor
    Weapon(std::string name, int damage, bool type);

    // getters for object attributes
    std::string getName();
    int getDamage();
    bool getType();
};


#endif
