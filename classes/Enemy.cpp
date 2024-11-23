#include "Enemy.h"

#include <string>
#include "Character.h"
#include "Buff.h"
#include "Weapon.h"

Enemy::Enemy(const std::string& name, int health, int strength, int magicRes, int meleeRes, Weapon* equipped_weapon) {
    this->name = name;
    this->health = health;
    maxHealth = health;
    this->strength = strength;
    this->magicRes = magicRes;
    this->meleeRes = meleeRes;
    this->equipped_weapon = equipped_weapon;
}

const std::string Enemy::getName() {
    return name;
}

Weapon Enemy::getWeapon() {
    return *equipped_weapon;
}

int Enemy::getHealth() {
    return health;
}
void Enemy::setHealth(int amount) {
    health = amount;
}
int Enemy::getMaxHealth() {
    return maxHealth;
}
int Enemy::getStrength() {
    return strength;
}
void Enemy::setStrength(int amount) {
    strength = amount;
}
int Enemy::getMagicRes() {
    return magicRes;
}
void Enemy::setMagicRes(int amount) {
    magicRes = amount;
}
int Enemy::getMeleeRes() {
    return meleeRes;
}
void Enemy::setMeleeRes(int amount) {
    meleeRes = amount;
}

void Enemy::attack(Character* target) {
    if(strength + equipped_weapon->getDamage() - target->getDefense() < 0) {
        cout << "The enemy did 0 damage to the " << target->getName() << endl;
    }
    else {
        target->setHealth(target->getHealth() - (strength + equipped_weapon->getDamage() - target->getDefense()));
        cout << "The enemy did " << to_string(strength + equipped_weapon->getDamage() - target->getDefense()) << " damage to the " << target->getName() << endl;
        if(target->getHealth() - (strength + equipped_weapon->getDamage() - target->getDefense()) < 0) {
            target->setHealth(0);
        }
    }
}
