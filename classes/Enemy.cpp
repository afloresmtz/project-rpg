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
    target.changeHealth(strength);
    // will do further calculations for defense here
}
void Enemy::applyBuff(Enemy& ally, Buff current_buff) {
    // will be done on next delivery
}
void Enemy::applyDebuff(Character target, Buff current_debuff) {
    // will be done on next delivery
}
