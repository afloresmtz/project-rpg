#include "Enemy.h"

Enemy::Enemy(int health, int strength, int magicRes, int meleeRes) {
    this->health = health;
    maxHealth = health;
    this->strength = strength;
    this->magicRes = magicRes;
    this->meleeRes = meleeRes;
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

void Enemy::attack(Character target) {
    target.setHealth(target.getHealth() - (strength - target.getDefense()));
}
void Enemy::applyBuff(Buff current_buff) {
    current_buff.affectEnemyStat();
}
void Enemy::applyDebuff(Buff current_debuff) {
    current_debuff.affectCharacterStat();
}
