#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
private:
    // Character attributes
    string name;
    int health;
    int maxHealth;
    int defense;
    int meleeDmg;
    int magicDmg;
    int mana;
    int maxMana;
    int critChance;
    int critDmg;
    Weapon current_weapon;

public:
    Character(string name, int health, int defense, int meleeDmg, Weapon current_weapon);
    Character(string name, int health, int defense, int magicDmg, Weapon current_weapon);

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
    void equipWeapon(Weapon new_weapon);

    void attackMelee(Enemy target);
    void attackMagic(Enemy target);
    void applyDebuff(Enemy target, Buff current_debuff);
    void applyBuff(Character& ally, Buff current_buff);

};

#endif
