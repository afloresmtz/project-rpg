#include "Character.h"

Character::Character(string name, int health, int defense, int meleeDmg, Weapon current_weapon) {
    this->name = name;
    this->health = health;
    maxHealth = health;
    this->defense = defense;
    this->meleeDmg = meleeDmg;
    this->current_weapon = current_weapon;

    critChance = 5;
    critDmg = 50;
}
Character::Character(string name, int health, int defense, int magicDmg, Weapon current_weapon) {
    this->name = name;
    this->health = health;
    maxHealth = health;
    this->defense = defense;
    this->magicDmg = magicDmg;
    this->current_weapon = current_weapon;

    mana = 100;
    maxMana = mana;
    critChance = 5;
    critDmg = 50;
    healthRegen = 0;
}

int Character::getHealth() {
    return health;
}
void Character::setHealth(int amount) {
    health = amount;
}
int Character::getMaxHealth() {
    return maxHealth;
}
void Character::setMaxHealth(int amount) {
    maxHealth = amount;
}
int Character::getDefense() {
    return defense;
}
void Character::setDefense(int amount) {
    defense = amount;
}
int Character::getMeleeDmg() {
    return meleeDmg;
}
void Character::setMeleeDmg(int amount) {
    meleeDmg = amount;
}
int Character::getMagicDmg() {
    return magicDmg;
}
void Character::setMagicDmg(int amount) {
    magicDmg = amount;
}
int Character::getMana() {
    return mana;
}
void Character::setMana(int amount) {
    mana = amount;
}
int Character::getMaxMana(){
    return maxMana;
}
void Character::setMaxMana(int amount){
    maxMana = amount;
}
int Character::getCritChance() {
    return critChance;
}
void Character::setCritChance(int amount) {
    critChance = amount;
}
int Character::getCritDmg() {
    return critDmg;
}
void Character::setCritDmg(int amount) {
    critDmg = amount;
}

Weapon getWeapon() {
    return current_weapon;
}
void equipWeapon(Weapon new_weapon) {
    current_weapon = new_weapon;
}

void Character::attackMelee(Enemy target) {
    // code inside of method
}
void Character::attackMagic(Enemy target) {
    // code inside of method
}

void Character::applyDebuff(Enemy target, Buff current_debuff) {
    // will be done on next delivery
}
void Character::applyBuff(Character& ally, Buff current_buff) {
    // will be done on next delivery
}

void guard() {
}
