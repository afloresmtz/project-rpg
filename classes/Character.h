#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
class Weapon;
#include "Enemy.h"

class Character {
private:
    // Character attributes
    std::string name;
    int health;
    int maxHealth;
    int defense;
    int meleeDmg;
    int magicDmg;
    int mana;
    int maxMana;
    int critChance;
    int critDmg;
    Weapon* current_weapon;

public:
    Character(const std::string name, int health, int defense, int damage, Weapon* current_weapon);

    const std::string getName();

    int getHealth();
    void setHealth(int amount);

    int getMaxHealth();
    void setMaxHealth(int amount);

    int getDefense();
    void setDefense(int amount);

    int getMeleeDmg();
    void setMeleeDmg(int amount);

    int getMagicDmg();
    void setMagicDmg(int amount);

    int getMana();
    void setMana(int amount);

    int getMaxMana();
    void setMaxMana(int amount);

    int getCritChance();
    void setCritChance(int amount);

    int getCritDmg();
    void setCritDmg(int amount);

    Weapon getWeapon();
    void equipWeapon(Weapon* new_weapon);

    void attackMelee(Enemy* target);
    void attackMagic(Enemy* target, int mana_amount);
    void guard();

};

#endif
