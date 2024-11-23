#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Character.h"
#include "Buff.h"
#include "Weapon.h"

class Enemy {
private:
    // private attributes
    std::string name;
    int health;
    int maxHealth;
    int strength;
    int magicRes;
    int meleeRes;
    // composition attribute
    Weapon* equipped_weapon;
public:
    // constructor
    Enemy(const std::string& name, int health, int strength, int magicRes, int meleeRes, Weapon* equipped_weapon);
    
    // getters and setters for all stats
    const std::string getName();
    Weapon getWeapon();

    int getHealth();
    void setHealth(int amount);

    int getMaxHealth();

    int getStrength();
    void setStrength(int amount);

    int getMagicRes();
    void setMagicRes(int amount);

    int getMeleeRes();
    void setMeleeRes(int amount);
    
    // action method
    void attack(Character* target);
};

#endif
