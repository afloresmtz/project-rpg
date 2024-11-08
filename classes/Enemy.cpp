#include "Enemy.h"

Enemy::Enemy(Stat health, Stat strength, Stat magicRes, Stat meleeRes) {
    this->health = health;
    this->strength = strength;
    this->magicRes = magicRes;
    this->meleeRes = meleeRes;
}

void Enemy::changeHealth(int amount) {
    health = health + amount;
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
