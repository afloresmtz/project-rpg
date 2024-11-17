#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    string name;
    int damage;
    bool type;
public:
    Weapon(string name, int damage, bool type);

    string getName();
    int getDamage();
    bool getType();
};


#endif
