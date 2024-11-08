#include "Character.h"

Character::Character(Stat health, Stat defense, Stat meleeDmg) {
    this->health = health;
    maxHealth = health;
    this->defense = defense;
    this->meleeDmg = meleeDmg;

    critChance = 5;
    critDmg = 50;
    healthRegen = 0;
}

Character::Character(Stat health, Stat defense, Stat magicDmg) {
    this->health = health;
    maxHealth = health;
    this->defense = defense;
    this->magicDmg = magicDmg;

    mana = 100;
    critChance = 5;
    critDmg = 50;
    healthRegen = 0;
}

void Character::changeHealth(int amount) {
    health = health + amount;
}
void Character::changeMana(int amount) {
    mana = mana + amount;
}

void Character::attackMelee(Enemy target) {
    target.changeHealth(meleeDmg);
    // still need to do damage reduction calculations here
}
void Character::attackMagic(Enemy target) {
    target.changeHealth(magicDmg);
    // still need to do damage reduction calculations here
}

void Character::applyDebuff(Enemy target, Buff current_debuff) {
    // will be done on next delivery
}
void Character::applyBuff(Character& ally, Buff current_buff) {
    // will be done on next delivery
}

void Character::regenHealth(Character& ally, int amount) {
    ally.changeHealth(amount);
}
void Character::regenMana(Character& ally, int amount) {
    ally.changeMana(amount);
}
