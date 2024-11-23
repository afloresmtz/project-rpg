#include "Enemy.h"

#include <string>
#include "Character.h"
#include "Buff.h"

Enemy::Enemy(const std::string& name, int health, int strength, int magicRes, int meleeRes) {
    this->name = name;
    this->health = health;
    maxHealth = health;
    this->strength = strength;
    this->magicRes = magicRes;
    this->meleeRes = meleeRes;
}

const std::string Enemy::getName() {
    return name;
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
    if(strength - target->getDefense() < 0) {
        cout << "The enemy did 0 damage to the " << target->getName() << endl;
    }
    else {
        target->setHealth(target->getHealth() - (strength - target->getDefense()));
        cout << "The enemy did " << to_string(strength - target->getDefense()) << " damage to the " << target->getName() << endl;
        if(target->getHealth() - (strength - target->getDefense()) < 0) {
            target->setHealth(0);
        }
    }
}
void Enemy::applyBuff(Buff current_buff) {
    current_buff.affectEnemyStat();
}
void Enemy::applyDebuff(Buff current_debuff) {
    current_debuff.affectCharacterStat();
}
