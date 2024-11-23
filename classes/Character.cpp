#include "Character.h"
#include <string>
#include <time.h>
#include <ctime>
#include <bits/stdc++.h>
#include "Weapon.h"
#include "Enemy.h"
#include "BlessedWeapon.h"

using namespace std;

// constructor
Character::Character(const std::string& name, int health, int defense, int damage, BlessedWeapon* current_weapon) {
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
// getters and setters for all stats
const std::string Character::getName() {
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

BlessedWeapon Character::getWeapon() {
    return *current_weapon;
}
void Character::equipWeapon(BlessedWeapon* new_weapon) {
    current_weapon = new_weapon;
}

// action methods

void Character::attackMelee(Enemy* target) {
    int dmg_recieved = (meleeDmg + current_weapon->getDamage()) * (2 - (0.02 * target->getMeleeRes()));
    srand(time(nullptr));
    int random_roll = rand() % (101);
    if(random_roll < critChance){
            dmg_recieved = dmg_recieved * ((100 + critDmg) / 100);
            cout << "Critical hit!\n" << endl;
    }
    target->setHealth(target->getHealth() - dmg_recieved);
}

void Character::attackMagic(Enemy* target, int mana_amount) {
    if(mana - mana_amount >= 0){
        int dmg_recieved = (magicDmg + current_weapon->getDamage()) * (2 - (0.02 * target->getMagicRes()));
        srand(time(nullptr));
        int random_roll = rand() % (101);
        if(random_roll < critChance){
            dmg_recieved = dmg_recieved * ((100 + critDmg) / 100);
            cout << "Critical hit!\n" << endl;
        }
        target->setHealth(target->getHealth() - dmg_recieved);
        mana = mana - mana_amount;
    }
    else {
        cout << "Not enough mana!" << endl;
    }
}

void Character::guard() {
    defense = defense + 10;
}
