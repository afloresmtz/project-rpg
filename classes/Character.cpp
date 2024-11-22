#include "Character.h"

Character::Character(string name, int health, int defense, int damage, Weapon current_weapon) {
    this->name = name;
    this->health = health;
    maxHealth = health;
    this->defense = defense;
    magicDmg = damage;
    meleeDmg = damage;
    this->current_weapon = current_weapon;

    mana = 100;
    maxMana = mana;
    critChance = 5;
    critDmg = 50;
}

string Character::getName() {
    return name;
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
    int dmg_recieved = (meleeDmg + current_weapon.getDamage()) * (2 - (0.02 * target.getMeleeRes()));
    target.setHealth(target.getHealth() - dmg_recieved);
}
void Character::attackMagic(Enemy target, int mana_amount) {
    if(mana - mana_amount >= 0){
        int dmg_recieved = (magicDmg + current_weapon.getDamage()) * (2 - (0.02 * target.getMagicRes()));
        target.setHealth(target.getHealth() - dmg_recieved);
        mana = mana - mana_amount;
    }
}

void Character::applyDebuff(Buff current_debuff, int mana_amount) {
    if(mana - mana_amount > 0){
        current_debuff.affectEnemyStat();
        mana = mana - mana_amount;
    }
    // still missing turn calculations for when the debuff ends
    // will do in next delivery when main.cpp is created and functional
    
}
void Character::applyBuff(Buff current_buff, int mana_amount) {
    if(mana - mana_amount > 0){
        current_debuff.affectCharacterStat();
        mana = mana - mana_amount;
    }
    // still missing turn calculations for when the buff ends
    // will do in next delivery when main.cpp is created and functional
}

void guard() {
    defense = defense * 2;
    
    // remove effect when it's the character's turn again
    // original_value = defense;
    // when it's their turn again:
    // defense = original_value;
}
